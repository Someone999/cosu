cmake_minimum_required(VERSION 3.29)
project(cosu)

set(CMAKE_CXX_STANDARD 20)

add_executable(cosu main.cpp
        memory/memory_reader.h
        memory/memory_reader.cpp
        utils/convert.h
        process/process.cpp
        process/process.h
        process/process_watcher.cpp
        process/process_watcher.h
        process/process_finder.cpp
        process/process_finder.h
        memory/pattern_manager.cpp
        memory/pattern_manager.h
        memory/enumerator/windows_memory_enumerator.cpp
        memory/enumerator/windows_memory_enumerator.h
        memory/enumerator/memory_region.cpp
        memory/enumerator/memory_region.h
        memory/pattern_address_manager.cpp
        memory/pattern_address_manager.h
        initializers/initializer.h
        initializers/initialize_data.h
        initializers/initializer_chain.cpp
        initializers/initializer_chain.h
        global_data.cpp
        global_data.h
        initializers/memory_pattern_initializer.cpp
        initializers/memory_pattern_initializer.h
        patterns/memory_pattern.cpp
        patterns/memory_pattern.h
        patterns/memory_pattern.h
        initializers/static_initializer.cpp
        initializers/static_initializer.h
        read_items/read_item.h
        read_items/read_item.cpp
        read_items/mania_key_state_read_item.cpp
        read_items/mania_key_state_read_item.h
        read_items/read_item_list.cpp
        read_items/read_item_list.h
        read_items/mania_key_overlay.cpp
        read_items/mania_key_overlay.h
        state_resetters/state_resetter.cpp
        state_resetters/state_resetter.h
        state_resetters/global_state_resetter.cpp
        state_resetters/global_state_resetter.h
        state_resetters/state_resetter_chain.cpp
        state_resetters/state_resetter_chain.h
        utils/iterator.h
        state_resetters/static_state_resetter.cpp
        state_resetters/static_state_resetter.h
        initializers/read_items_initializer.cpp
        initializers/read_items_initializer.h
        pointers/pointer_chain.cpp
        pointers/pointer_chain.h
)



add_subdirectory(${CMAKE_SOURCE_DIR}/external/projects/LightningScanner-1.0.2)
target_link_libraries(cosu LightningScanner)
include_directories(${CMAKE_SOURCE_DIR}/external/projects/LightningScanner-1.0.2/include)