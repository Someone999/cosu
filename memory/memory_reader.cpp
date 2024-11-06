//
// Created by HSMan on 24-11-3.
//
#include "memory_reader.h"
#include "../utils/convert.h"
using namespace utils::convert;
int8_t memory_reader::read_byte(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 1);
    auto ret = no_exception_unchecked_dereference_as<int8_t>(ptr);
    delete[] ptr;
    return ret;
}

int16_t memory_reader::read_int16(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 2);
    auto ret = no_exception_unchecked_dereference_as<int16_t>(ptr);
    delete[] ptr;
    return ret;
}


uint16_t memory_reader::read_uint16(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 2);
    auto ret = no_exception_unchecked_dereference_as<uint16_t>(ptr);
    delete[] ptr;
    return ret;
}

int32_t memory_reader::read_int32(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 4);
    auto ret = no_exception_unchecked_dereference_as<int32_t>(ptr);
    delete[] ptr;
    return ret;
}


uint32_t memory_reader::read_uint32(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 4);
    auto ret = no_exception_unchecked_dereference_as<uint32_t>(ptr);
    delete[] ptr;
    return ret;
}

int64_t memory_reader::read_int64(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 8);
    auto ret = no_exception_unchecked_dereference_as<int64_t>(ptr);
    delete[] ptr;
    return ret;
}


uint64_t memory_reader::read_uint64(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 8);
    auto ret = no_exception_unchecked_dereference_as<uint64_t>(ptr);
    delete[] ptr;
    return ret;
}

float memory_reader::read_float(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 4);
    auto ret = no_exception_unchecked_dereference_as<float>(ptr);
    delete[] ptr;
    return ret;
}

double memory_reader::read_double(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, 8);
    auto ret = no_exception_unchecked_dereference_as<double>(ptr);
    delete[] ptr;
    return ret;
}


char* memory_reader::read_bytes(HANDLE process_handle, uintptr_t address, SIZE_T size) {
    char* buffer = new char[size];
    memset(buffer, 0, size);
    SIZE_T realRead = 0;
    auto r = ReadProcessMemory(process_handle, (void*)address, buffer, size, &realRead);
    if(!r || realRead != size) {
        return nullptr;
    }

    return buffer;
}

uintptr_t memory_reader::read_uintptr(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, sizeof(uintptr_t));
    auto ret = no_exception_unchecked_dereference_as<uintptr_t>(ptr);
    delete[] ptr;
    return ret;
}

intptr_t memory_reader::read_intptr(HANDLE process_handle, uintptr_t address) {
    auto ptr = read_bytes(process_handle, address, sizeof(intptr_t));
    auto ret = no_exception_unchecked_dereference_as<intptr_t>(ptr);
    delete[] ptr;
    return ret;
}