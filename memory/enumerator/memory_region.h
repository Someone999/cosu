//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_MEMORY_REGION_H
#define OSUKPS_MEMORY_REGION_H
#include<Windows.h>

class memory_region {
    SIZE_T size_;
    unsigned char* start_address_;
    HANDLE process_handle_;
    MEMORY_BASIC_INFORMATION mem_basic_info_;

public:
    memory_region(SIZE_T size, unsigned char* start_address, HANDLE process_handle, MEMORY_BASIC_INFORMATION memory_basic_information);

    [[nodiscard]] SIZE_T get_size() const;

    [[nodiscard]] unsigned char *get_start_address() const;

    [[nodiscard]] const void *get_process_handle() const;
    MEMORY_BASIC_INFORMATION get_memory_basic_info() const;
    ~memory_region();
};


#endif //OSUKPS_MEMORY_REGION_H
