//
// Created by HSMan on 24-11-3.
//

#ifndef OSUKPS_PROCESS_FINDER_H
#define OSUKPS_PROCESS_FINDER_H


#include "process.h"
#include <tlhelp32.h>


class process_finder {
public:
    static bool find_process(const wchar_t* process_name, std::vector<process*>* processes);
};


#endif //OSUKPS_PROCESS_FINDER_H
