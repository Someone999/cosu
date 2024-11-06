//
// Created by HSMan on 24-11-5.
//

#include "static_state_resetter.h"
#include "state_resetter_chain.h"
#include "global_state_resetter.h"

void static_state_resetter::reset_state() {
    state_resetter_chain resetter_chain;
    resetter_chain.add_state_resetter(new global_state_resetter());
    resetter_chain.reset_all();
}
