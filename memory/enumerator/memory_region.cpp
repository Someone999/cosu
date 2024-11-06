//
// Created by HSMan on 24-11-4.
//

#include "memory_region.h"

SIZE_T memory_region::get_size() const {
    return size_;
}

unsigned char *memory_region::get_start_address() const {
    return start_address_;
}

const void *memory_region::get_process_handle() const {
    return process_handle_;
}

memory_region::memory_region(SIZE_T size,  unsigned char *start_address, HANDLE process_handle
                             , MEMORY_BASIC_INFORMATION memory_basic_information)
:size_(size),
start_address_(start_address),
process_handle_(process_handle),
 mem_basic_info_(memory_basic_information){
}

memory_region::~memory_region() {
    delete[] this->start_address_;
}

MEMORY_BASIC_INFORMATION memory_region::get_memory_basic_info() const {
    return mem_basic_info_;
}
