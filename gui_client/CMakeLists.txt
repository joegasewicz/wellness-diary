cmake_minimum_required(VERSION 3.22)
project(gui_client C)

set(CMAKE_C_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})
add_executable(gui_client gui.c symptom.c symptom.h activity.c activity.h utils.c utils.h)
target_link_libraries(gui_client ${GTK3_LIBRARIES})

