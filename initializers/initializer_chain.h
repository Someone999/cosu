//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_INITIALIZER_CHAIN_H
#define OSUKPS_INITIALIZER_CHAIN_H

#include<vector>
#include "initializer.h"
#include "initialize_data.h"

class initializer_chain {
    std::vector<initializer*> initializers_;
public:
    void initialize_all(initialize_data* data);
    void add_initializer(initializer* i);
    void remove_initializer(initializer* i);
};


#endif //OSUKPS_INITIALIZER_CHAIN_H
