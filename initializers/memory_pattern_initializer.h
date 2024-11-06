//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_MEMORY_PATTERN_INITIALIZER_H
#define OSUKPS_MEMORY_PATTERN_INITIALIZER_H


#include "initializer.h"
#include "../memory/enumerator/memory_region.h"

class memory_pattern_initializer : public initializer {
    static void resolve_loop();
    static void resolve_patterns(memory_region* region, std::vector<std::string>* resolved_memory_pattern_name);
    static void add_patterns();
public:
    void initialize(initialize_data* data) override;
};


#endif //OSUKPS_MEMORY_PATTERN_INITIALIZER_H
