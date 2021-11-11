cmake_minimum_required(VERSION 3.21)
project(_embed_mono)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(EngineLib)
add_subdirectory(GameExe)