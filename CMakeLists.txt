cmake_minimum_required(VERSION 3.10)
project(logger )

# require a C++ compiler
# use it for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

# find includes in the corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# find fmt
find_package(fmt)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
)

# your source files
set(src
    src/main.cpp
    src/logger.cpp src/logger.hpp
)

# name of the .exe file, window flag and the list of things to compile
add_executable(${PROJECT_NAME} ${src})

# also tell CMake to link with the libraries from find_package
# otherwise it'll think that you wanted to find those just for fun and won't link them
target_link_libraries(
    ${PROJECT_NAME}
    fmt::fmt
)
