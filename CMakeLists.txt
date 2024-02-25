cmake_minimum_required(VERSION 3.12)

project(demo VERSION 0.1)

find_package(PkgConfig REQUIRED)

# target_include_directories(${PROJECT_NAME} PRIVATE ../common)
add_executable(${PROJECT_NAME} main.cpp HashTable.hpp)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME})


project(tests LANGUAGES CXX)

add_executable(${PROJECT_NAME} tests/test_demo.cpp tests/catch_amalgamated.cpp)
