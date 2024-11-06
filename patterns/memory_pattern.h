//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_MEMORY_PATTERN_H
#define OSUKPS_MEMORY_PATTERN_H
#include "LightningScanner/LightningScanner.hpp"
#include "../memory/enumerator/memory_region.h"

using namespace LightningScanner;
typedef uintptr_t (*pattern_resolved_proc)(ScanResult&, memory_region&);

class memory_pattern {
    const char* pattern_;
public:
    explicit memory_pattern(const char* pattern, pattern_resolved_proc pattern_resolved_proc = nullptr);
    const char* get_pattern();
    pattern_resolved_proc pattern_resolved = nullptr;
};


#endif //OSUKPS_MEMORY_PATTERN_H
