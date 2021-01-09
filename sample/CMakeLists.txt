cmake_minimum_required(VERSION 3.1)
project("sample")

add_subdirectory(include/driver_pkg)
link_libraries(driver_pkg)
add_executable(sample src/sample.cpp)
target_link_libraries(sample driver_pkg)