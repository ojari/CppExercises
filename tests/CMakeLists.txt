cmake_minimum_required(VERSION 3.12)

project(test2demo LANGUAGES CXX)

add_executable(${PROJECT_NAME} test_demo.cpp catch_amalgamated.cpp)

#find_package(Catch2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)

#enable_testing()

#add_test(NAME test2demo COMMAND ${PROJECT_NAME})