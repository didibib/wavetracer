cmake_minimum_required(VERSION 3.18.0)

# Check if project is build in seperate folder
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()

# Define paths
set(WAVE_VENDOR_DIR "${CMAKE_SOURCE_DIR}/vendor")
set(STB "${WAVE_VENDOR_DIR}/stb")

# Include cmake modules
include(cmake/update_submodules.cmake)
include(cmake/set_startup_project.cmake)
include(cmake/set_precompiled_header.cmake)
include(cmake/ignore_precompiled_header.cmake)
include(cmake/set_target_output_directories.cmake)

# Set the project name and version
project(wavetracer VERSION 1.0)

# Use folder structure 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Specify the c++ standard
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED true)
# Setup output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)

# Update all git submodules (function found in: cmake/)
update_submodules()

# Start building
message(STATUS "Adding subdirectory 'glm'")
add_subdirectory(${WAVE_VENDOR_DIR}/glm)

message(STATUS "Adding subdirectory 'spdlog'")
add_subdirectory(${WAVE_VENDOR_DIR}/spdlog)

message(STATUS "Adding subdirectory 'src'")
add_subdirectory(src)

# (function found in: cmake/)
set_startup_project(wavetracer)