//
// Created by HSMan on 24-11-3.
//

#include <vector>
#include <memory>

#include "process_finder.h"

std::unique_ptr<PROCESSENTRY32W> create_process32_entry() {
    auto entry = PROCESSENTRY32W();
    entry.dwSize = sizeof(PROCESSENTRY32W);
    return std::make_unique<PROCESSENTRY32W>(entry);
}


bool process_finder::find_process(const wchar_t *process_name, std::vector<process*> *processes) {
    if(processes == nullptr) {
        return false;
    }

    HANDLE tool = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(tool == nullptr || tool == INVALID_HANDLE_VALUE) {
        return false;
    }
    auto entry = create_process32_entry();
    if(!Process32FirstW(tool, entry.get())) {
        CloseHandle(tool);
        return false;
    }

    if(wcscmp(process_name, entry->szExeFile) == 0) {
        processes->emplace_back(new process(entry->th32ProcessID));
    }

    while(Process32NextW(tool, entry.get())) {
        if(wcscmp(process_name, entry->szExeFile) == 0) {
            processes->emplace_back(new process(entry->th32ProcessID));
        }
    }

    CloseHandle(tool);
    return !processes->empty();
}
