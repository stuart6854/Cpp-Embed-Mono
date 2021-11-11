//
// Created by stumi on 11/11/21.
//

#include <iostream>
#include "Game.h"

#include "CSBind.h"

#include "RandomNum.h"
#include "Console.h"

namespace Game
{
    Game::Game()
    {
        // Where mono is located
        mono_set_dirs(".", ".");

        // Create mono domain
        monoDomain = mono_jit_init("Game");
        if (monoDomain)
        {
            // Load a mono assembly (CSharpGameLib.dll)
            gameAssembly = mono_domain_assembly_open(monoDomain, "CSharpGameLib.dll");
            if (gameAssembly)
            {
                // Loading mono image
                gameAssemblyImage = mono_assembly_get_image(gameAssembly);
                if (gameAssemblyImage)
                {
                    // Add internal calls
                    mono_add_internal_call("Engine.RandomNum::getRandomInt()", &Engine::RandomNum::getRandomInt);
                    mono_add_internal_call("Engine.RandomNum::getRandomFloat()", &Engine::RandomNum::getRandomFloat);
                    mono_add_internal_call("Engine.Console::clearBuffer()", &Engine::Console::clearBuffer);
                    mono_add_internal_call("Engine.Console::flush()", &Engine::Console::flush);
                    mono_add_internal_call("Engine.Console::putString(string)", &CSBind::CS_Console_putString);

                    // Find IGame
                    MonoClass* iGameClass = mono_class_from_name(gameAssemblyImage, "CSharpGameLib", "IGame");
                    MonoClass* mainClass = mono_class_from_name(gameAssemblyImage, "CSharpGameLib", "GameMain");
                    if (iGameClass && mainClass)
                    {
                        // Describe method
                        MonoMethodDesc* mainMethodDesc = mono_method_desc_new(".GameMain:main()", false);
                        if (mainMethodDesc)
                        {
                            // Find main in main class
                            MonoMethod* mainMethod = mono_method_desc_search_in_class(mainMethodDesc, mainClass);
                            if (mainMethod)
                            {
                                // Call main method
                                MonoObject* exObject = nullptr;
                                gameObject = mono_runtime_invoke(mainMethod, nullptr, nullptr, &exObject);
                                if (gameObject)
                                {
                                    // Ref count object on c++ side
                                    gameObjectGCHandle = mono_gchandle_new(gameObject, false);

                                    // Get tick function
                                    MonoMethodDesc* tickMethodDesc = mono_method_desc_new(".IGame:tick()", false);
                                    if (tickMethodDesc)
                                    {
                                        // Get real function
                                        MonoMethod* virtualMethod = mono_method_desc_search_in_class(tickMethodDesc, iGameClass);
                                        if (virtualMethod)
                                        {
                                            tickMethod = mono_object_get_virtual_method(gameObject, virtualMethod);
                                        }

                                        // Free
                                        mono_method_desc_free(tickMethodDesc);
                                    }

                                    // Get key event function
                                    MonoMethodDesc* keyEventMethodDesc = mono_method_desc_new(".IGame:keyEvent(char)", false);
                                    if (keyEventMethodDesc)
                                    {
                                        // Get real function
                                        MonoMethod* virtualMethod = mono_method_desc_search_in_class(keyEventMethodDesc, iGameClass);
                                        if (virtualMethod)
                                        {
                                            keyEventMethod = mono_object_get_virtual_method(gameObject, virtualMethod);
                                        }

                                        // Free
                                        mono_method_desc_free(keyEventMethodDesc);
                                    }
                                }

                                // Report exception
                                if (exObject)
                                {
                                    MonoString* exString = mono_object_to_string(exObject, nullptr);
                                    std::string exCppString = mono_string_to_utf8(exString);
                                    std::cerr << "Mono Invoke issue: " << exCppString << std::endl;
                                }
                            }

                            // Free desc
                            mono_method_desc_free(mainMethodDesc);
                        }
                    }
                }
            }
        }
    }

    Game::~Game()
    {
        // Release mono handles
        if (gameObjectGCHandle)
        {
            mono_gchandle_free(gameObjectGCHandle);
        }

        // Release the domain
        if (monoDomain)
        {
            mono_jit_cleanup(monoDomain);
        }
    }

    void Game::keyEvent(char key)
    {
        if (keyEventMethod)
        {
            // Invoke with exception
            MonoObject* exObject = nullptr;
            void* args[] = { &key };
            mono_runtime_invoke(keyEventMethod, gameObject, args, &exObject);

            // Report exception
            if (exObject)
            {
                MonoString* exString = mono_object_to_string(exObject, nullptr);
                std::string exCppString = mono_string_to_utf8(exString);
                std::cerr << "Mono Invoke issue: " << exCppString << std::endl;
            }
        }
    }

    bool Game::tick()
    {
        bool result = false;

        if (tickMethod)
        {
            // Invoke with exception
            MonoObject* exObject = nullptr;
            MonoObject* returnObject = mono_runtime_invoke(tickMethod, gameObject, nullptr, &exObject);

            // Extract if result was ok
            if (returnObject)
            {
                result = *(bool*)mono_object_unbox(returnObject);
            }

            // Report exception
            if (exObject)
            {
                MonoString* exString = mono_object_to_string(exObject, nullptr);
                std::string exCppString = mono_string_to_utf8(exString);
                std::cerr << "Mono Invoke issue: " << exCppString << std::endl;
            }
        }

        return result;
    }

}  // namespace Game