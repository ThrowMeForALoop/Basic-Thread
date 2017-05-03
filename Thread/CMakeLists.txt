cmake_minimum_required (VERSION 2.6)

# Project name
project (Threads)

# Version
#build file

# Project paths
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Output paths
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Compile and link flags
FILE (GLOB ThreadSrc ${PROJECT_SRC_DIR}/*.cpp)
FILE (GLOB ThreadInc ${PROJECT_INCLUE_DIR}/*.h)

# Add Include 
include_directories ("${PROJECT_INCLUDE_DIR}")

# Build execute file
add_executable (Threads ${ThreadSrc} ${ThreadInc})
target_link_libraries (Threads pthread)

