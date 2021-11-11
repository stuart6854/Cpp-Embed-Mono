//
// Created by stumi on 11/11/21.
//

#ifndef _EMBED_MONO_CSBIND_H
#define _EMBED_MONO_CSBIND_H

#include <mono/metadata/object.h>

namespace Game
{
    class CSBind
    {
    public:
        static void CS_Console_putString(MonoString* str);
    };
}  // namespace Game

#endif  //_EMBED_MONO_CSBIND_H
