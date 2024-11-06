//
// Created by HSMan on 24-11-5.
//

#ifndef OSUKPS_MANIA_KEY_OVERLAY_H
#define OSUKPS_MANIA_KEY_OVERLAY_H

#include <string>
class mania_key_state {
    int key_code;
    bool is_pressed;
public:
    mania_key_state(int key_code, bool is_pressed);
    mania_key_state();
    std::string get_as_string() const;
    [[nodiscard]] int get_key_code() const;
    [[nodiscard]] bool get_is_pressed() const;
};


#endif //OSUKPS_MANIA_KEY_OVERLAY_H
