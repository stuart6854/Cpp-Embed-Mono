project(GameExe)

add_executable(GameExe src/main.cpp)

target_include_directories(GameExe PUBLIC include PRIVATE src)

target_link_libraries(GameExe PRIVATE EngineLib)

target_compile_definitions(GameExe PRIVATE "ENGINE_DLL")