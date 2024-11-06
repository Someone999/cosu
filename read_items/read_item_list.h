//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_READ_ITEM_LIST_H
#define OSUKPS_READ_ITEM_LIST_H
#include<vector>
#include<mutex>
#include "read_item.h"

class read_item_list {
    std::vector<read_item*> read_items_;
    std::mutex read_write_lock_;
public:
    void add_read_item(read_item* read_item);
    void remove_read_item(read_item* read_item);
    void update_all();
    void clear();
    ~read_item_list();
};


#endif //OSUKPS_READ_ITEM_LIST_H
