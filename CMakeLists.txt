cmake_minimum_required(VERSION 3.22)
project(pacman)

include(ExternalProject)

# Set correct flags for compiler
set(CMAKE_CXX_FLAGS "-Wall")

# generate compile commands (use for lsp completion clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy assets to build dir
set(assets ${CMAKE_CURRENT_SOURCE_DIR}/assets)
file(COPY ${assets} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#Compile vendors
set(vendors ${CMAKE_CURRENT_SOURCE_DIR}/vendors)
ExternalProject_Add(
    spdlog 
    SOURCE_DIR "${vendors}/spdlog"
    PREFIX spdlog
    INSTALL_COMMAND ""
)

ExternalProject_Add(
    SDL 
    SOURCE_DIR "${vendors}/SDL"
    PREFIX SDL
    INSTALL_COMMAND ""
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${vendors}/spdlog/include)
include_directories(${vendors}/SDL/include)


# Add src game
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_subdirectory(src)



