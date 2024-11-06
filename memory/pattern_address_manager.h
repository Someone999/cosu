//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_PATTERN_ADDRESS_MANAGER_H
#define OSUKPS_PATTERN_ADDRESS_MANAGER_H


#include "pattern_manager.h"

class pattern_address_manager {
    pattern_manager* pattern_mgr_;
    std::unordered_map<std::string, uintptr_t> addresses_;
public:
    explicit pattern_address_manager(pattern_manager* pattern_mgr);
    void replace_address(const std::string& key, uintptr_t address);
    void remove_address(const std::string& key);
    uintptr_t get_address(const std::string& key);
    bool try_get_address(const std::string& key, uintptr_t* address);
    [[nodiscard]] bool is_valid_address(const std::string& key) const;
    void clear();
    size_t size();
};


#endif //OSUKPS_PATTERN_ADDRESS_MANAGER_H
