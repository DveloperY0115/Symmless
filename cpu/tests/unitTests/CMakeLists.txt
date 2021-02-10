# Set target name
set(target UnitTests)

# Find sources in current directory
file(GLOB sources
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Build executables
add_executable(${target}
        ${sources})

# Link libraries
target_link_libraries(${target} gmock gtest)