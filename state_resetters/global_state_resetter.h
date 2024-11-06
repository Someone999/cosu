//
// Created by HSMan on 24-11-5.
//

#ifndef OSUKPS_GLOBAL_STATE_RESETTER_H
#define OSUKPS_GLOBAL_STATE_RESETTER_H


#include "state_resetter.h"

class global_state_resetter : public state_resetter {
public:
    void reset_state() override;
};


#endif //OSUKPS_GLOBAL_STATE_RESETTER_H
