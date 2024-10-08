
if (WIN32)
  set(VCPKG_DIR c:/usr/vcpkg)
  set(VCPKG_ROOT ${VCPKG_DIR}/installed/x64-windows)
  set(CURL_LIB libcurl)
  set(EXTRA_LIBRARIES libcrypto libssl)
else()
  set(VCPKG_DIR /home/jari/vcpkg)
  set(VCPKG_ROOT ${VCPKG_DIR}/installed/x64-linux)
  set(CURL_LIB curl)
  set(EXTRA_LIBRARIES ssl crypto pthread dl z)
endif()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake)

cmake_minimum_required(VERSION 3.12)


project(tests LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME}
  main.cpp
  assignment2.cpp
  tests/test_assignment1.cpp
  tests/test_assignment2.cpp
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
)



project(life LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME}
  life.cpp
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
)
