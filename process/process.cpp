//
// Created by HSMan on 24-11-3.
//

#include "process.h"
process::process(DWORD pid) {
    pid_ = pid;
    process_handle_ = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
}

bool process::is_exited() {
    DWORD ret_code = 0;
    if(!GetExitCodeProcess(process_handle_, &ret_code)) {
        return true;
    }

    if(ret_code != STILL_ACTIVE) {
        return true;
    }

    // If the process is not exited, the function will return a timeout
    // Otherwise the function returns 0 immediately
    return WaitForSingleObject(process_handle_, 500) == 0;
}

DWORD process::get_pid() {
    return pid_;
}

HANDLE process::get_process_handle() {
    return process_handle_;
}
