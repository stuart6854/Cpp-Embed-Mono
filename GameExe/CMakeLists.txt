project(GameExe)

add_executable(GameExe
        src/main.cpp
        src/Mono.cpp
        )

target_include_directories(GameExe PUBLIC include PRIVATE src ${CMAKE_SOURCE_DIR}/dependencies/mono/include/mono-2.0)

target_link_libraries(GameExe PRIVATE EngineLib "${CMAKE_SOURCE_DIR}/dependencies/mono/lib/mono-2.0-sgen.lib")

target_compile_definitions(GameExe PRIVATE "ENGINE_DLL")

add_custom_command(TARGET GameExe POST_BUILD
        # Copy Resources
        # COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/${example_name}/resources/ ${CMAKE_CURRENT_BINARY_DIR}/resources/

        # Libraries
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/dependencies/mono/bin/mono-2.0-sgen.dll" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/dependencies/mono/lib/mono/4.5/" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mono/4.5/"
        )