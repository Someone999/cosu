//
// Created by HSMan on 24-11-4.
//

#include "unordered_map"
#include "string"
#include "../patterns/memory_pattern.h"

#ifndef OSUKPS_PATTERN_MANAGER_H
#define OSUKPS_PATTERN_MANAGER_H

class pattern_manager {
    typedef std::unordered_map<std::string, memory_pattern> pattern_map;
    pattern_map patterns_;
public:
    void add_pattern(const std::string& key, memory_pattern pattern);
    void remove_pattern(const std::string& key);
    memory_pattern get_pattern(const std::string& key);
    bool try_get_pattern(const std::string& key, memory_pattern* pattern);
    pattern_map::const_iterator get_patterns_begin();
    pattern_map::const_iterator get_patterns_end();
    void clear();
    size_t size();
};


#endif //OSUKPS_PATTERN_MANAGER_H
