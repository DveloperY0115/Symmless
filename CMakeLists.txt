cmake_minimum_required(VERSION 3.17)
project(BLAS)
# project(BLAS CUDA)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(cpu)
add_subdirectory(gpu)