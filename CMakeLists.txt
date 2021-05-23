cmake_minimum_required(VERSION 3.17)
project(Symmless)
# project(Symmless CUDA)

set(CMAKE_CXX_STANDARD 20)

# googletest
include_directories(libraries/googletest/googletest/include)
include_directories(libraries/googletest/googlemock/include)
add_subdirectory(libraries/googletest)

include_directories(core/includes)

add_subdirectory(tests)