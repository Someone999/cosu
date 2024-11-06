//
// Created by HSMan on 24-11-5.
//

#include "mania_key_overlay.h"

int mania_key_state::get_key_code() const {
    return key_code;
}

bool mania_key_state::get_is_pressed() const {
    return is_pressed;
}

mania_key_state::mania_key_state(int key_code, bool is_pressed) : key_code(key_code), is_pressed(is_pressed) {}

mania_key_state::mania_key_state() : key_code(0), is_pressed(false) {
}

std::string mania_key_state::get_as_string() const {
    std::string s = std::to_string(key_code) + "(" + (is_pressed ? "True" : "False") + ")";
    return s;
}
