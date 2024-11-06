//
// Created by HSMan on 24-11-4.
//

#include <iostream>
#include "memory_pattern_initializer.h"
#include "../global_data.h"
#include "../memory/enumerator/windows_memory_enumerator.h"
#include "LightningScanner/LightningScanner.hpp"
#include "../utils/convert.h"

using namespace utils::convert;
void memory_pattern_initializer::initialize(initialize_data* data) {
    auto d = global_data::get_default();
    d->pattern_mgr->clear();
    d->pattern_address_mgr->clear();
    add_patterns();
    resolve_loop();
}
void memory_pattern_initializer::add_patterns() {
    auto d = global_data::get_default();
    d->pattern_mgr->add_pattern("rulesets", memory_pattern("7D 15 A1 ?? ?? ?? ?? 85 C0"));

}

void memory_pattern_initializer::resolve_patterns(memory_region* region, std::vector<std::string>* resolved_memory_pattern_name) {
    auto d = global_data::get_default();
    auto it = d->pattern_mgr->get_patterns_begin();
    for(auto i = it; i != d->pattern_mgr->get_patterns_end(); ++i) {
        const auto& pair = *i;
        auto find_result = std::find(resolved_memory_pattern_name->begin(), resolved_memory_pattern_name->end(), pair.first);
        if(find_result != resolved_memory_pattern_name->end()) {
            continue;
        }

        auto pattern = pair.second;

        auto pattern_str = pattern.get_pattern();
        LightningScanner::Scanner scanner((Pattern(pattern_str)));
        auto result = scanner.Find(region->get_start_address(), region->get_size());
        auto region_base = region->get_start_address();
        auto mem_basic_info = region->get_memory_basic_info();
        auto appear_address = result.Get<uint8_t>();
        if(appear_address == nullptr) {
            continue;
        }

        auto offset = appear_address - region_base;
        auto real_address = (char*) nullptr;
        if(pattern.pattern_resolved != nullptr) {
            real_address = (char*) pattern.pattern_resolved(result, *region) + offset;
        } else {
            real_address = (char*)mem_basic_info.BaseAddress + offset;
        }


        if(real_address == nullptr) {
           continue;
        }

        resolved_memory_pattern_name->emplace_back(pair.first);
        d->pattern_address_mgr->replace_address(pair.first, (uintptr_t)real_address);
    }
}

void memory_pattern_initializer::resolve_loop() {
    auto d = global_data::get_default();
    auto p = d->watcher->get_current_process();
    while (p == nullptr || p->is_exited()) {
        std::cout << "Waiting for osu! process..." << '\n';
        Sleep(1000);
    }

    std::vector<std::string> resolved_memory_pattern_name;
    windows_memory_enumerator enumerator(p->get_process_handle());
    while(true) {
        if(resolved_memory_pattern_name.size() >= d->pattern_mgr->size()) {
            break;
        }

        auto next = enumerator.get_next();
        if(next == nullptr) {
            break;
        }

        if(next->get_start_address() == nullptr) {
            continue;
        }

        resolve_patterns(next, &resolved_memory_pattern_name);
    }
}

