cmake_minimum_required (VERSION 2.8)
project (hades)

find_package(OpenCV)
include_directories (${OpenCV_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "-lpthread -lsqlite3 -fPIC -Wall -I/usr/local/include -I/usr/local/include/FL/images -D_THREAD_SAFE -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -L/usr/local/lib -lfltk -lm -ldl -framework Cocoa")

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
target_link_libraries(bin/hadesd ${OpenCV_LIBS})
