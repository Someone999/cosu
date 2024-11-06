//
// Created by HSMan on 24-11-3.
//

#ifndef OSUKPS_PROCESS_WATCHER_H
#define OSUKPS_PROCESS_WATCHER_H
#include <Windows.h>
#include <Tlhelp32.h>
#include "process.h"
#include <atomic>
#include <memory>
#include <vector>
#include <mutex>

class process_watcher;
struct process_watcher_config;
typedef void(*process_startup_callback)(process_watcher*, process*);
typedef void(*process_stop_callback)(process_watcher*, process*);

class process_watcher {
    uintptr_t current_thread_;
    process* current_process_;
    std::atomic<process_watcher_config*>* config_;
    const wchar_t* process_name_;
    std::vector<process_startup_callback> startup_callbacks_;
    std::vector<process_stop_callback> stop_callbacks_;
    static process* find_next_process(process_watcher_config cfg);
public:

    static void watch_loop(void* arg);
    explicit process_watcher(const wchar_t*);
    void start_watch();
    void stop_watch();
    void register_startup_callback(process_startup_callback callback);
    void register_stop_callback(process_stop_callback callback);
    process* get_current_process();
};

struct process_watcher_config {
    std::atomic<bool>* stop_flag = new std::atomic<bool>();
    std::atomic<process_watcher*>* process_watcher_ins = new std::atomic<process_watcher*>();
    std::atomic<int>* detect_delay = new std::atomic<int>;
    std::atomic<bool>* is_first_startup = new std::atomic<bool>;
    std::mutex* process_read_write_mutex = new std::mutex;
};



#endif //OSUKPS_PROCESS_WATCHER_H
