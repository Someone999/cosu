//
// Created by HSMan on 24-11-5.
//

#include "state_resetter_chain.h"
#include "../utils/iterator.h"

void state_resetter_chain::add_state_resetter(state_resetter *state_resetter) {
    if(utils::iterator::find(reset_states_resetter_, state_resetter).has_value()) {
        return;
    }

    reset_states_resetter_.emplace_back(state_resetter);
}

void state_resetter_chain::remove_state_resetter(state_resetter *state_resetter) {

    utils::iterator::remove_one(reset_states_resetter_, state_resetter);
}

void state_resetter_chain::reset_all() {
    for(auto r: reset_states_resetter_) {
        r->reset_state();
    }
}

void state_resetter_chain::clear() {

}
