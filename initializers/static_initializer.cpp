//
// Created by HSMan on 24-11-4.
//

#include "static_initializer.h"

#include <utility>
#include "initializer_chain.h"
#include "memory_pattern_initializer.h"
#include "read_items_initializer.h"

void static_initializer::initialize(initialize_data* data) {
    initializer_chain chain;
    chain.add_initializer(new memory_pattern_initializer());
    chain.add_initializer(new read_items_initializer());
    chain.initialize_all(data);
}
