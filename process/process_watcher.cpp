//
// Created by HSMan on 24-11-3.
//

#include "process_watcher.h"
#include <thread>
#include <vector>
#include "../utils/convert.h"
#include "process_finder.h"
using namespace utils::convert;


process_watcher::process_watcher(const wchar_t * process_name) {
    process_name_ = process_name;
    current_thread_ = 0;
    current_process_ = nullptr;
    config_ = new std::atomic<process_watcher_config*>();
    config_->store(new process_watcher_config);
    config_->load()->process_watcher_ins->store(this);
    config_->load()->detect_delay->store(1000);
    config_->load()->is_first_startup->store(true);
}

process* process_watcher::find_next_process(process_watcher_config cfg) {
    std::vector<process*> processes;
    if(!process_finder::find_process(cfg.process_watcher_ins->load()->process_name_, &processes)) {
        return nullptr;
    }

    auto ret = processes[0];
    for(auto & process : processes) {
        if(process == ret) {
            continue;
        }

        delete process;
    }

    processes.clear();
    return ret;
}

void process_watcher::watch_loop(void* arg) {

    if(arg == nullptr) {
        throw std::exception();
    }

    auto cfg = unsafe_dereference_as<process_watcher_config>(arg);
    try {

        while(!cfg.stop_flag->load()) {
            auto current_process = cfg.process_watcher_ins->load()->current_process_;
            if(current_process == nullptr) {
                auto next_process = find_next_process(cfg);
                if(next_process == nullptr) {
                    continue;
                }

                cfg.process_read_write_mutex->lock();
                cfg.process_watcher_ins->load()->current_process_ = next_process;
                cfg.process_read_write_mutex->unlock();

                for(auto callback: cfg.process_watcher_ins->load()->startup_callbacks_) {
                    callback(*cfg.process_watcher_ins, next_process);
                }


                Sleep(cfg.detect_delay->load());

                continue;
            }

            if(current_process->is_exited()) {
                for(auto callback: cfg.process_watcher_ins->load()->stop_callbacks_) {
                    callback(*cfg.process_watcher_ins, current_process);
                }

                cfg.process_read_write_mutex->lock();
                delete cfg.process_watcher_ins->load()->current_process_;
                cfg.process_watcher_ins->load()->current_process_ = nullptr;
                cfg.process_read_write_mutex->unlock();
                Sleep(cfg.detect_delay->load());
                continue;
            }
        }

        Sleep(cfg.detect_delay->load());
    }
    catch(...) {
        cfg.process_read_write_mutex->unlock();
    }
}

void process_watcher::start_watch() {
    if(current_thread_ != 0 && current_process_ != nullptr && !current_process_->is_exited()) {
        return;
    }

    config_->load()->stop_flag->store(false);
    current_thread_ = _beginthread((_beginthread_proc_type) watch_loop, 0, config_->load());
}

void process_watcher::stop_watch() {
    if(current_thread_ == 0) {
        return;
    }

    config_->load()->stop_flag->store(true);
}

void process_watcher::register_startup_callback(process_startup_callback callback) {
    startup_callbacks_.emplace_back(callback);
}

void process_watcher::register_stop_callback(process_stop_callback callback) {
    stop_callbacks_.emplace_back(callback);
}

process* process_watcher::get_current_process() {
    auto mutex = config_->load()->process_read_write_mutex;
    try {
        mutex->lock();
        auto ret = current_process_;
        mutex->unlock();
        return ret;
    }
    catch(...) {
        mutex->unlock();
        return nullptr;
    }
}