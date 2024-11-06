//
// Created by HSMan on 24-11-4.
//

#include "pattern_manager.h"
#include "../patterns/memory_pattern.h"

void pattern_manager::add_pattern(const std::string &key, memory_pattern pattern) {
    patterns_.insert(std::pair(key, pattern));
}

void pattern_manager::remove_pattern(const std::string &key) {
    patterns_.erase(key);
}

memory_pattern pattern_manager::get_pattern(const std::string &key) {
    auto i = patterns_.find(key);
    if(i == patterns_.end()) {
        return memory_pattern(nullptr, nullptr);
    }

    return i->second;
}

pattern_manager::pattern_map::const_iterator pattern_manager::get_patterns_begin() {
    return patterns_.cbegin();
}

pattern_manager::pattern_map::const_iterator pattern_manager::get_patterns_end() {
    return patterns_.cend();
}

bool pattern_manager::try_get_pattern(const std::string &key, memory_pattern* pattern) {
    auto i = patterns_.find(key);
    if(i == patterns_.end()) {
        return false;
    }

    auto current = i->second;
    if(pattern != nullptr) {
        *pattern = current;
    }

    return true;
}

void pattern_manager::clear() {
    patterns_.clear();
}

size_t pattern_manager::size() {
    return patterns_.size();
}

