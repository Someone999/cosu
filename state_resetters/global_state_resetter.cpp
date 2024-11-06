//
// Created by HSMan on 24-11-5.
//

#include "global_state_resetter.h"
#include "../global_data.h"

void global_state_resetter::reset_state() {
    auto def = global_data::get_default();
    def->pattern_mgr->clear();
    def->read_items->clear();
    def->pattern_address_mgr->clear();
}
