cmake_minimum_required(VERSION 3.22)
project(gui_client C)

# libraries
add_library(json_store STATIC /home/joe/CLionProjects/libjson_store/libjson_store.c)
target_include_directories(json_store PUBLIC /home/joe/CLionProjects/libjson_store)

set(CMAKE_C_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})
add_executable(gui_client
        gui.c
        symptom.c symptom.h
        activity.c activity.h
        utils.c utils.h mental.c
        mental.h
        /home/joe/CLionProjects/libjson_store/libjson_store.c
        /home/joe/CLionProjects/libjson_store/libjson_store.h
        )

target_link_libraries(gui_client PUBLIC
        ${GTK3_LIBRARIES}
        /home/joe/CLionProjects/libjson_store
        )
