cmake_minimum_required(VERSION 3.17)
project(BLAS)
# project(BLAS CUDA)

set(CMAKE_CXX_STANDARD 14)

include_directories(libraries/googletest/googletest/include)
include_directories(libraries/googletest/googlemock/include)

add_subdirectory(libraries/googletest)

add_subdirectory(cpu)
add_subdirectory(gpu)