//
// Created by HSMan on 24-11-4.
//
#ifndef OSUKPS_WINDOWS_MEMORY_ENUMERATOR_H
#define OSUKPS_WINDOWS_MEMORY_ENUMERATOR_H
#include<Windows.h>
#include<atomic>
#include "memory_region.h"

class windows_memory_enumerator {
    HANDLE process_handle_;
    std::atomic<bool> is_first_access;
    void* current_address_;
    static SYSTEM_INFO get_system_info();
    SYSTEM_INFO system_info{};
public:
    explicit windows_memory_enumerator(HANDLE process_handle);
    memory_region* get_next();
    void reset();

};


#endif //OSUKPS_WINDOWS_MEMORY_ENUMERATOR_H
