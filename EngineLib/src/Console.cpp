//
// Created by stumi on 11/11/21.
//
#include "Console.h"

#include <iostream>

namespace Engine
{
    void Console::clearBuffer() { std::cout << "clearBuffer" << std::endl; }

    void Console::flush() { std::cout << "flush" << std::endl; }

    void Console::putString(std::string str) { std::cout << str << std::endl; }

}  // namespace Engine
