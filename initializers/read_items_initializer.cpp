//
// Created by HSMan on 24-11-6.
//

#include "read_items_initializer.h"
#include "../global_data.h"
#include "../read_items/mania_key_state_read_item.h"
void read_items_initializer::initialize(initialize_data *data) {
    auto d = global_data::get_default();
    d->read_items->add_read_item(new mania_key_state_read_item());
}
