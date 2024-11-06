//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_MANIA_KEY_STATE_READ_ITEM_H
#define OSUKPS_MANIA_KEY_STATE_READ_ITEM_H

#include "read_item.h"
#include "mania_key_overlay.h"
#include "../pointers/pointer_chain.h"

class mania_key_state_read_item : public read_item {
    static void read_array_object(uintptr_t array_obj_base);
    static mania_key_state read_array_item(uintptr_t array_address);
    pointer_chain* chain;
public:
    mania_key_state_read_item();
    void update_state() override;
    void reset() override;
};


#endif //OSUKPS_MANIA_KEY_STATE_READ_ITEM_H
