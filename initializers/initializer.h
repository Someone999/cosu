//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_INITIALIZER_H
#define OSUKPS_INITIALIZER_H

#include "initialize_data.h"

class initializer {
public:
    virtual void initialize(initialize_data* data) = 0;
};
#endif //OSUKPS_INITIALIZER_H
