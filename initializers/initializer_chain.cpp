//
// Created by HSMan on 24-11-4.
//

#include "initializer_chain.h"
#include "../utils/iterator.h"

void initializer_chain::initialize_all(initialize_data* data) {
    for(auto initializer: initializers_) {
        initializer->initialize(data);
    }
}

void initializer_chain::add_initializer(initializer* i) {
    if(utils::iterator::find(initializers_, i).has_value()) {
        return;
    }

    initializers_.emplace_back(i);
}

void initializer_chain::remove_initializer(initializer* i) {
    utils::iterator::remove_one(initializers_, i);
}
