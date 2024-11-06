//
// Created by HSMan on 24-11-3.
//

#include <Windows.h>
#ifndef OSUKPS_PROCESS_H
#define OSUKPS_PROCESS_H


class process {
    DWORD pid_;
    HANDLE process_handle_;
public:
    explicit process(DWORD pid);
    bool is_exited();
    DWORD get_pid();
    HANDLE get_process_handle();

};


#endif //OSUKPS_PROCESS_H
