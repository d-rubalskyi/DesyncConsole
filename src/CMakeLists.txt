cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_STANDARD 17)

project(DesyncConsole)

add_subdirectory(ThirdParty/DesyncCompare/src)

add_executable(DesyncConsole main.cpp)

target_include_directories(DesyncConsole PUBLIC ThirdParty/DesyncCompare/src)
target_link_libraries(DesyncConsole DesyncCompare)
