//
// Created by stumi on 11/11/21.
//

#include "CSBind.h"

#include "Console.h"

namespace Game
{
    /*
     Putting string into C#

     MonoString* outputStr = nullptr;
     const char* cppStr = "Hello World!";
     if(cppStr)
        outputStr = mono_string_new(mono_domain_get(), cppStr);

     return outputStr

     */

    void CSBind::CS_Console_putString(MonoString* str) { Engine::Console::putString(mono_string_to_utf8(str)); }

}  // namespace Game