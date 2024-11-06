//
// Created by HSMan on 24-11-4.
//

#include "memory_pattern.h"

memory_pattern::memory_pattern(const char *pattern, pattern_resolved_proc pattern_resolved_proc) {
    pattern_ = pattern;
    pattern_resolved = pattern_resolved_proc;
}

const char *memory_pattern::get_pattern() {
    return pattern_;
}
