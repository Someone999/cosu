//
// Created by HSMan on 24-11-5.
//

#ifndef OSUKPS_STATE_RESETTER_CHAIN_H
#define OSUKPS_STATE_RESETTER_CHAIN_H

#include<vector>
#include "state_resetter.h"

class state_resetter_chain {
    std::vector<state_resetter*> reset_states_resetter_;
public:
    void add_state_resetter(state_resetter* state_resetter);
    void remove_state_resetter(state_resetter* state_resetter);
    void reset_all();
    void clear();
};


#endif //OSUKPS_STATE_RESETTER_CHAIN_H
