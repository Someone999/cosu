//
// Created by HSMan on 24-11-4.
//

#include <iostream>
#include <sstream>
#include "mania_key_state_read_item.h"
#include "../global_data.h"
#include "../memory/memory_reader.h"
#include "mania_key_overlay.h"

void mania_key_state_read_item::update_state() {
    auto d = global_data::get_default();
    auto addr = d->pattern_address_mgr->get_address("rulesets");
    auto root = chain->get_root();
    if(addr != root->get_pointer()) {
        root->set_pointer(addr - 0xB);
    }

    auto level6 =
            root->read_final_pointer(d->watcher->get_current_process()->get_process_handle());

    if(!level6.has_value()) {
        return;
    }

    read_array_object(level6.value());
}

void mania_key_state_read_item::reset() {
    read_item::reset();
}

void mania_key_state_read_item::read_array_object(uintptr_t array_obj_base) {
    auto d = global_data::get_default();
    auto handle = d->watcher->get_current_process()->get_process_handle();
    memory_reader reader;
    auto arr_base = reader.read_uintptr(handle, array_obj_base + 0x4);
    auto arr_size = reader.read_int32(handle, array_obj_base + 0xC);
    auto* states = new mania_key_state[arr_size];
    bool any_key_pressed = false;
    for(int i = 0; i < arr_size; i++) {
        auto current_address = arr_base + i * 4 + 8;
        states[i] = read_array_item(current_address);
        any_key_pressed |= states[i].get_is_pressed();
    }

    if(!any_key_pressed) {
        delete[] states;
        return;
    }

    std::stringstream s;
    for(int i = 0; i < arr_size; i++) {
        s << states[i].get_as_string();
        if(i < arr_size - 1) {
            s << ", ";
        }
    }

    s << '\n';
    std::cout << s.str();

    delete[] states;

}

mania_key_state mania_key_state_read_item::read_array_item(uintptr_t array_address) {
    auto d = global_data::get_default();
    auto handle = d->watcher->get_current_process()->get_process_handle();
    memory_reader reader;
    uintptr_t element_address = reader.read_uintptr(handle, array_address);
    auto key_code_address = element_address + 0x30;
    auto is_pressed_address = element_address + 0x3B;
    int key_code = reader.read_int32(handle, key_code_address);
    bool is_pressed = reader.read_byte(handle, is_pressed_address) != 0;
    return {key_code, is_pressed};
}

mania_key_state_read_item::mania_key_state_read_item() {
    auto addr = global_data::get_default()->pattern_address_mgr->get_address("rulesets");
    chain = new pointer_chain(addr - 0xB, 0, nullptr, nullptr);
    chain = chain->create_or_get_next(0x4)->create_or_get_next(0xD0)
            ->create_or_get_next(0x94)->create_or_get_next(0x4)->create_or_get_next(0x44);
}
