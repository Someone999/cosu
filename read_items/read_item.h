//
// Created by HSMan on 24-11-4.
//

#ifndef OSUKPS_READ_ITEM_H
#define OSUKPS_READ_ITEM_H

class read_item {
public:
    virtual void update_state() = 0;
    virtual void reset();
    virtual ~read_item();
};
#endif //OSUKPS_READ_ITEM_H
