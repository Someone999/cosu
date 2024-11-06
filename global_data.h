//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_GLOBAL_DATA_H
#define OSUKPS_GLOBAL_DATA_H
#include <atomic>

#include "memory/pattern_manager.h"
#include "memory/pattern_address_manager.h"
#include "process/process_watcher.h"
#include "read_items/read_item_list.h"

class global_data {
    global_data();
    static std::atomic<global_data*> current_global_data_;
public:
    pattern_manager* pattern_mgr;
    pattern_address_manager* pattern_address_mgr;
    process_watcher* watcher;
    read_item_list* read_items;
    static global_data* get_default();
};


#endif //OSUKPS_GLOBAL_DATA_H
