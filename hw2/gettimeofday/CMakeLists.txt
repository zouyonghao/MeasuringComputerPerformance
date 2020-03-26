cmake_minimum_required(VERSION 3.10)
project(gettiemofday)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost 1.65.1 REQUIRED COMPONENTS date_time filesystem system)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(gettiemofday main.cpp)
target_link_libraries(gettiemofday ${Boost_LIBRARIES})

add_executable(rdtsc rdtsc.cpp)
target_link_libraries(rdtsc ${Boost_LIBRARIES})