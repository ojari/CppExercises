
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

project(tests LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

find_package(Catch2 REQUIRED)

add_executable(${PROJECT_NAME}
    tests/test_decorator.cpp
    tests/test_flyweight.cpp
    tests/test_proxy.cpp
    tests/test_chain_of_resp.cpp
    tests/test_interpreter.cpp
    tests/test_mediator.cpp
    tests/test_memento.cpp
    tests/test_observer.cpp
    tests/test_state.cpp
    tests/test_visitor.cpp
    main.cpp
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
