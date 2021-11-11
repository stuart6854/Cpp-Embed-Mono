project(EngineLib)

add_library(EngineLib
        SHARED
        src/Engine.cpp
        src/Application.cpp
        src/RandomNum.cpp
        src/Console.cpp
        )

target_include_directories(EngineLib PUBLIC include PRIVATE src)

target_compile_definitions(EngineLib PRIVATE "_ENGINE_BUILD_DLL")