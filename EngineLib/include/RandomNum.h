//
// Created by stumi on 11/11/21.
//

#ifndef _EMBED_MONO_RANDOMNUM_H
#define _EMBED_MONO_RANDOMNUM_H

#include "Base.h"

namespace Engine
{
    class ENGINE_API RandomNum
    {
    public:
        static int getRandomInt();

        static float getRandomFloat();
    };
}  // namespace Engine

#endif  //_EMBED_MONO_RANDOMNUM_H
