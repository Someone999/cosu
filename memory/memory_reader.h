#include <Windows.h>
#include <cstdint>
#ifndef OSUKPS_MEMORY_MEMORYREADER
#define OSUKPS_MEMORY_MEMORYREADER
class safe_memory_reader {
public:
    virtual bool try_read_byte(HANDLE process_handle, void* address, int8_t* val) = 0;
    virtual bool try_read_int16(HANDLE process_handle, void* address, int16_t* val) = 0;
    virtual bool try_read_uint16(HANDLE process_handle, void* address, uint16_t* val) = 0;
    virtual bool try_read_int32(HANDLE process_handle, void* address, int32_t* val) = 0;
    virtual bool try_read_uint32(HANDLE process_handle, void* address, uint32_t* val) = 0;
    virtual bool try_read_int64(HANDLE process_handle, void* address, int64_t* val) = 0;
    virtual bool try_read_uint64(HANDLE process_handle, void* address, uint64_t* val) = 0;
    virtual bool try_read_float(HANDLE process_handle, void* address, float* val) = 0;
    virtual bool try_read_double(HANDLE process_handle, void* address, double* val) = 0;
    virtual bool try_read_bytes(HANDLE process_handle, void* address, SIZE_T size, char** result) = 0;
    virtual uintptr_t read_uintptr(HANDLE process_handle, void* address, SIZE_T size) = 0;
    virtual intptr_t read_intptr(HANDLE process_handle, void* address, SIZE_T size) = 0;
};

class memory_reader {
public:
    virtual int8_t read_byte(HANDLE process_handle, uintptr_t address);
    virtual int16_t read_int16(HANDLE process_handle, uintptr_t address);
    virtual uint16_t read_uint16(HANDLE process_handle, uintptr_t address);
    virtual int32_t read_int32(HANDLE process_handle, uintptr_t address);
    virtual uint32_t read_uint32(HANDLE process_handle, uintptr_t address);
    virtual int64_t read_int64(HANDLE process_handle, uintptr_t address);
    virtual uint64_t read_uint64(HANDLE process_handle, uintptr_t address);
    virtual float read_float(HANDLE process_handle, uintptr_t address);
    virtual double read_double(HANDLE process_handle, uintptr_t address);
    virtual char* read_bytes(HANDLE process_handle, uintptr_t address, SIZE_T size);
    virtual uintptr_t read_uintptr(HANDLE process_handle, uintptr_t address);
    virtual intptr_t read_intptr(HANDLE process_handle, uintptr_t address);
};

#endif