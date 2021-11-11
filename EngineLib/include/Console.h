//
// Created by stumi on 11/11/21.
//

#ifndef _EMBED_MONO_Console_H
#define _EMBED_MONO_Console_H

#include "Base.h"

#include <string>

namespace Engine
{
    class ENGINE_API Console
    {
    public:
        static void clearBuffer();
        static void flush();

        static void putString(std::string str);
    };
}  // namespace Engine

#endif  //_EMBED_MONO_Console_H
