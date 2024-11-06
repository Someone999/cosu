//
// Created by HSMan on 24-11-6.
//

#include "pointer_chain.h"
#include "../memory/memory_reader.h"

pointer_chain::pointer_chain(uintptr_t pointer, int64_t offset, pointer_chain *parent, pointer_chain* root) :
ptr_(pointer), offset_(offset), parent_(parent),  root_(root) {
    next_ = nullptr;
}

std::optional<uintptr_t> pointer_chain::read_final_pointer(HANDLE process_handle) {
    if(root_ != nullptr || ptr_ == 0) {
        return std::nullopt;
    }

    memory_reader reader;
    auto current = this->ptr_;
    auto tmp_next = next_;
    while(current != 0) {
        auto result = reader.read_uintptr(process_handle, current);
        if(result == 0) {
            return std::nullopt;
        }

        current = result;
        if(tmp_next == nullptr) {
            return current;
        }

        current += tmp_next->offset_;
        tmp_next = tmp_next->next_;
    }

    return std::nullopt;
}

std::optional<uint8_t *> pointer_chain::get_final_pointer_as_c_pointer(HANDLE process_handle) {
    auto ptr = read_final_pointer(process_handle);
    if(!ptr.has_value()) {
        return std::nullopt;
    }

    return (uint8_t*) ptr.value();
}

pointer_chain *pointer_chain::create_or_get_next(int64_t offset) {
    if(next_ != nullptr) {
        return next_;
    }

    next_ = new pointer_chain(0, offset, this, root_ == nullptr ? this : root_);
    return next_;
}

uintptr_t pointer_chain::get_pointer() const {
    return ptr_;
}

size_t pointer_chain::get_offset() const {
    return offset_;
}

pointer_chain *pointer_chain::get_root() {
    return root_;
}

pointer_chain *pointer_chain::get_parent() {
    return parent_;
}

void pointer_chain::set_pointer(uintptr_t ptr) {
    ptr_ = ptr;
}

void pointer_chain::set_offset(size_t offset) {
    offset_ = offset;
}

bool pointer_chain::is_root() {
    return root_ == nullptr && parent_ == nullptr;
}

pointer_chain* pointer_chain::copy() {
    auto* current = this;  // 这里开始复制链表
    auto* head = new pointer_chain(current->ptr_, current->offset_, current->parent_, current->root_);
    auto* copied = head;  // head 保存链表的头

    while (current->next_ != nullptr) {
        current = current->next_;

        if(copied == nullptr) {
            return nullptr;
        }

        copied->next_ = new pointer_chain(current->ptr_, current->offset_, current->parent_, current->root_);
        copied = copied->next_;
    }

    return head;
}
