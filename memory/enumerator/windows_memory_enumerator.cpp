//
// Created by HSMan on 24-11-4.
//

#include "windows_memory_enumerator.h"


memory_region* windows_memory_enumerator::get_next() {
    if (is_first_access.load()) {
        current_address_ = system_info.lpMinimumApplicationAddress;
        is_first_access.store(false);
    }

    if (current_address_ >= system_info.lpMaximumApplicationAddress) {
        return nullptr;
    }

    MEMORY_BASIC_INFORMATION mbi = {};
    if (!VirtualQueryEx(process_handle_, current_address_, &mbi, sizeof(MEMORY_BASIC_INFORMATION))) {
        return new memory_region{0, nullptr, process_handle_, mbi};
    }

    if(mbi.Protect == PAGE_NOACCESS || mbi.Protect == PAGE_GUARD || mbi.State != MEM_COMMIT) {
        current_address_ = (char*)current_address_+ mbi.RegionSize;
        return new memory_region{ 0, nullptr, process_handle_, mbi};
    }



    auto read_length = mbi.RegionSize;


    auto* buffer = new unsigned char[read_length]; // 分配缓冲区
    memset(buffer, 0, read_length);
    SIZE_T real_read = 0;
    if (!ReadProcessMemory(process_handle_, current_address_, buffer, read_length, &real_read)) {
        auto err_code = GetLastError();
        current_address_ = static_cast<char*>(current_address_) + read_length; // 更新地址
        delete[] buffer;
        return new memory_region{0, nullptr, process_handle_, mbi};
    }

    current_address_ = static_cast<char*>(current_address_) + read_length; // 更新地址
    return new memory_region{read_length, buffer, process_handle_, mbi};
}

SYSTEM_INFO windows_memory_enumerator::get_system_info() {
    SYSTEM_INFO sys_info;
    GetSystemInfo(&sys_info);
    return sys_info;
}

windows_memory_enumerator::windows_memory_enumerator(HANDLE process_handle) {
    process_handle_ = process_handle;
    current_address_ = nullptr;
    system_info = get_system_info();
    is_first_access.store(true);
}

void windows_memory_enumerator::reset() {
    current_address_ = nullptr;
}
