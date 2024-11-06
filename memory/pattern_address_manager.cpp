//
// Created by HSMan on 24-11-4.
//

#include "pattern_address_manager.h"

#include <utility>
pattern_address_manager::pattern_address_manager(pattern_manager* pattern_mgr) {
    pattern_mgr_ = pattern_mgr;
}



void pattern_address_manager::replace_address(const std::string &key, uintptr_t address) {

    auto result = pattern_mgr_->try_get_pattern(key, nullptr);
    if(!result) {
        return;
    }

    addresses_[key] = address;
}

void pattern_address_manager::remove_address(const std::string &key) {
    pattern_mgr_->remove_pattern(key);
    addresses_.erase(key);
}

uintptr_t pattern_address_manager::get_address(const std::string &key) {
    if(!is_valid_address(key)) {
        return 0;
    }

    auto i = addresses_.find(key);
    if(i == addresses_.end()) {
        return 0;
    }

    return i->second;
}

bool pattern_address_manager::try_get_address(const std::string &key, uintptr_t *address) {
    auto addr = get_address(key);
    if(addr == 0) {
        return false;
    }

    if(address) {
        *address = addr;
    }

    return true;
}

bool pattern_address_manager::is_valid_address(const std::string &key) const {
    auto i = addresses_.find(key);
    return i != addresses_.end() && i->second != 0;
}

void pattern_address_manager::clear() {
    addresses_.clear();
}

size_t pattern_address_manager::size() {
    return addresses_.size();
}

