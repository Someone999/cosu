//
// Created by HSMan on 24-11-3.
//

#include<exception>
#ifndef OSUKPS_CONVERT_H
#define OSUKPS_CONVERT_H

namespace utils::convert {
    template<typename T>
    inline T unsafe_dereference_as(void* pointer) {
        if(pointer == nullptr) {
            throw std::exception();
        }
        return *(T*) pointer;
    }

    template<typename T>
    inline T no_exception_unchecked_dereference_as(void* pointer) noexcept {
        if(pointer == nullptr) {
            return T();
        }

        return *(T*) pointer;
    }

}
#endif //OSUKPS_CONVERT_H

