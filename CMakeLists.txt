cmake_minimum_required (VERSION 2.6)
project (hades)

set (CMAKE_CXX_FLAGS "-lpthread -lsqlite3 -fPIC -Wall")

#version number
set (hades_VERSION_MAJOR 0)
set (hades_VERSION_MINOR 4)

#program info
#set (PROGRAM_NAME ""Hades"")

#miscellaneous
set (BUFFER_SIZE 256)

#configure file to add CMake settings to it
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)
include_directories ("${PROJECT_BINARY_DIR}")
add_executable (bin/hades hades.cpp)
add_executable (bin/hadesd hadesd.cpp)
