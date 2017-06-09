cmake_minimum_required (VERSION 2.8)
project (hades)

find_package(OpenCV REQUIRED)
find_package(FLTK REQUIRED)
find_package(Threads REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "-lsqlite3 -fPIC -Wall")

##version number
set (hades_VERSION_MAJOR 0)
set (hades_VERSION_MINOR 4)

#miscellaneous
set (BUFFER_SIZE 256)

#configure file to add CMake settings to it
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)
include_directories ("${PROJECT_BINARY_DIR}")
add_executable (hades hades.cpp)
add_executable (hadesd hadesd.cpp)
target_link_libraries(hadesd ${OpenCV_LIBS})
target_link_libraries(hadesd ${FLTK_LIBS})
target_link_libraries(hades ${OpenCV_LIBRARIES})
target_link_libraries(hades ${FLTK_LIBRARIES})
target_link_libraries(hadesd ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(hades ${CMAKE_THREAD_LIBS_INIT})
