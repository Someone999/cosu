//
// Created by HSMan on 24-11-4.
//

#include "read_item_list.h"
#include "../utils/iterator.h"

void read_item_list::add_read_item(read_item *read_item) {
    read_write_lock_.lock();
    if(utils::iterator::find(read_items_, read_item).has_value()) {
        return;
    }

    read_items_.emplace_back(read_item);
    read_write_lock_.unlock();
}

void read_item_list::remove_read_item(read_item *read_item) {
    read_write_lock_.lock();
    auto it = std::find(read_items_.begin(), read_items_.end(), read_item);
    if(it == read_items_.end()) {
        return;
    }

    read_items_.erase(it);
    read_write_lock_.unlock();
}

void read_item_list::update_all() {
    read_write_lock_.lock();
    for(auto member: read_items_) {
        member->update_state();
    }
    read_write_lock_.unlock();
}

read_item_list::~read_item_list() {
    read_write_lock_.lock();
    for(auto p: read_items_) {
        delete p;
    }

    read_write_lock_.unlock();
    read_items_.clear();
}

void read_item_list::clear() {
    read_items_.clear();
}
