
if (WIN32)
  set(VCPKG_DIR c:/usr/vcpkg)
  set(VCPKG_ROOT ${VCPKG_DIR}/installed/x64-windows)
  set(CURL_LIB libcurl)
  set(EXTRA_LIBRARIES libcrypto libssl)
else()
  set(VCPKG_DIR /home/jari/vcpkg-2024.02.14)
  set(VCPKG_ROOT ${VCPKG_DIR}/installed/x64-linux)
  set(CURL_LIB curl)
  set(EXTRA_LIBRARIES ssl crypto pthread dl z)
endif()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake)

cmake_minimum_required(VERSION 3.12)
project(demo VERSION 0.1)

# find_package(PkgConfig REQUIRED)

# target_include_directories(${PROJECT_NAME} PRIVATE ../common)
add_executable(${PROJECT_NAME} 
    main.cpp
    HashTable.hpp
    RecursiveAlgorithms.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


project(tests LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

find_package(Catch2 REQUIRED)

add_executable(${PROJECT_NAME}
    RecursiveAlgorithms.cpp
    Sorting.cpp
    tests/test_hashtable.cpp
    tests/test_bst.cpp
    tests/test_linklist.cpp
    tests/test_double_linklist.cpp
    tests/test_stack.cpp
    tests/test_queue.cpp
    tests/test_graph.cpp
    tests/test_recursive.cpp
    tests/test_sort.cpp
    tests/test_pattern_decorator.cpp
    tests/test_pattern_flyweight.cpp
    tests/test_pattern_proxy.cpp
    tests/test_pattern_chain_of_resp.cpp
    tests/test_pattern_interpreter.cpp
    tests/test_pattern_mediator.cpp
    tests/test_pattern_memento.cpp
    tests/catch_amalgamated.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


target_include_directories(${PROJECT_NAME} PRIVATE
    ${VCPKG_ROOT}/include
)
target_link_directories(${PROJECT_NAME} PRIVATE
    ${VCPKG_ROOT}/debug/lib
    ${VCPKG_ROOT}/debug/lib/manual-link
)
target_link_libraries(${PROJECT_NAME}
    Catch2d
    Catch2Maind
)
