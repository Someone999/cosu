//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_INITIALIZE_DATA_H
#define OSUKPS_INITIALIZE_DATA_H

#include "../memory/pattern_manager.h"
#include "../memory/pattern_address_manager.h"
#include <any>

class initialize_data {
public:
    std::unordered_map<std::string, std::any> data;
};

#endif //OSUKPS_INITIALIZE_DATA_H
