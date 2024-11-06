//
// Created by HSMan on 24-11-4.
//

#include "global_data.h"
global_data::global_data() {
    pattern_mgr = new pattern_manager;
    pattern_address_mgr = new pattern_address_manager(pattern_mgr);
    watcher = new process_watcher(L"osu!.exe");
    read_items = new read_item_list();
}

global_data* global_data::get_default() {
    if(current_global_data_.load() == nullptr) {
        current_global_data_.store(new global_data());
    }

    return current_global_data_.load();
}

std::atomic<global_data*> global_data::current_global_data_ = std::atomic<global_data*>();




