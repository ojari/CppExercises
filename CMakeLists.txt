cmake_minimum_required(VERSION 3.12)

project(demo VERSION 0.1)

# find_package(PkgConfig REQUIRED)

# target_include_directories(${PROJECT_NAME} PRIVATE ../common)
add_executable(${PROJECT_NAME} main.cpp HashTable.hpp RecursiveAlgorithms.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


project(tests LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME}
    RecursiveAlgorithms.cpp
    Sorting.cpp
    tests/test_demo.cpp
    tests/test_bst.cpp
    tests/test_linklist.cpp
    tests/test_double_linklist.cpp
    tests/test_stack.cpp
    tests/test_queue.cpp
    tests/test_graph.cpp
    tests/test_recursive.cpp
    tests/test_sort.cpp
    tests/catch_amalgamated.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)