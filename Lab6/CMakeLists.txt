cmake_minimum_required(VERSION 3.20)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/executables)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)

include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${PROJECT_SOURCE_DIR}/../Libs/headers)

add_library(UsefulLib STATIC ../Libs/src/UsefulLib.cpp)
add_library(solve STATIC src/solve.cpp)

# Найти и подключить GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавить исполняемый файл для тестов
add_executable(tests tests/tests.cpp)
target_link_libraries(tests GTest::gtest_main solve)

# Включить тестирование
enable_testing()
gtest_discover_tests(tests)

# Связать библиотеки
target_link_libraries(solve PRIVATE UsefulLib)
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE solve)

# Санитайзер
set(SAN "thread")
add_compile_options("-fsanitize=${SANITIZER}")
add_link_options("-fsanitize=${SANITIZER}")



