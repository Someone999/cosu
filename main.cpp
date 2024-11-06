
#include <iostream>
#include "process/process_watcher.h"
#include "LightningScanner/LightningScanner.hpp"
#include "memory/enumerator/windows_memory_enumerator.h"
#include "utils/convert.h"
#include "initializers/static_initializer.h"
#include "global_data.h"
#include "read_items/mania_key_state_read_item.h"
#include "state_resetters/state_resetter_chain.h"
#include "state_resetters/static_state_resetter.h"
#include "pointers/pointer_chain.h"

std::atomic<bool> block_main_loop;
void start_watcher() {
    auto w = global_data::get_default()->watcher;
    w->register_stop_callback([](process_watcher*, process*) {
        static_state_resetter::reset_state();
        block_main_loop.store(true);
    });
    w->register_startup_callback([](process_watcher *, process* p) {
        static_initializer::initialize(nullptr);
        block_main_loop.store(false);
    });

    w->start_watch();
}

int main() {
    block_main_loop.store(true);
    start_watcher();
    while(block_main_loop.load()) {
        Sleep(100);
    }

    auto d = global_data::get_default();



    while(true) {
        if(block_main_loop.load()) {
            Sleep(100);
            continue;
        }

        d->read_items->update_all();
        Sleep(0);
    }
}
