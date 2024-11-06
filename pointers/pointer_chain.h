//
// Created by HSMan on 24-11-6.
//

#ifndef COSU_POINTER_CHAIN_H
#define COSU_POINTER_CHAIN_H


#include <cstdint>
#include <optional>
#include <Windows.h>
class pointer_chain {
    pointer_chain* next_;
    uintptr_t ptr_;
    int64_t offset_;
    pointer_chain* parent_;
    pointer_chain* root_;
public:
    pointer_chain(uintptr_t pointer, int64_t offset, pointer_chain* parent, pointer_chain* root);
    std::optional<uintptr_t> read_final_pointer(HANDLE process_handle);
    std::optional<uint8_t*> get_final_pointer_as_c_pointer(HANDLE process_handle);
    pointer_chain* create_or_get_next(int64_t offset);
    [[nodiscard]] uintptr_t get_pointer() const;
    [[nodiscard]] size_t get_offset() const;
    pointer_chain* get_root();
    pointer_chain* get_parent();
    pointer_chain* copy();
    void set_pointer(uintptr_t ptr);
    void set_offset(size_t offset);
    bool is_root();

};


#endif //COSU_POINTER_CHAIN_H
