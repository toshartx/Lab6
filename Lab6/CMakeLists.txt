cmake_minimum_required(VERSION 3.00)
project(Lab6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_C_COMPILER /usr/bin/gcc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/executables)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)

include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${PROJECT_SOURCE_DIR}/../Libs/headers)


add_library(UsefulLib STATIC ../Libs/src/UsefulLib.cpp)
add_library(solve STATIC source/solve.cpp)

target_link_libraries(solve PRIVATE UsefulLib)
add_executable(main source/main.cpp)
target_link_libraries(main PRIVATE solve)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread -fsanitize=address")
endif()


