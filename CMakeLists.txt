cmake_minimum_required(VERSION 3.22)
project(pacman)

# Set correct flags for compiler
set(CMAKE_CXX_FLAGS "-Wall")

# generate compile commands (use for lsp completion clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy assets to build dir
set(assets ${CMAKE_CURRENT_SOURCE_DIR}/assets)
file(COPY ${assets} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#Compile vendors
set(vendors ${CMAKE_CURRENT_SOURCE_DIR}/vendors)
add_subdirectory(${vendors}/spdlog)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendors/spdlog/include)


# Add src game
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_subdirectory(src)



