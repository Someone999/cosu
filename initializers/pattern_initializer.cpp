//
// Created by HSMan on 24-11-7.
//

#include "pattern_initializer.h"
#include "../global_data.h"

void pattern_initializer::initialize(initialize_data *data) {
    auto g = global_data::get_default();
    g->pattern_mgr->clear();
    g->pattern_mgr->add_pattern("rulesets", memory_pattern("7D 15 A1 ?? ?? ?? ?? 85 C0"));
}
