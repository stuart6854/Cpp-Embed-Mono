//
// Created by stumi on 11/11/21.
//
#include "RandomNum.h"

#include <random>

namespace Engine
{
    int RandomNum::getRandomInt()
    {
        static std::default_random_engine e;
        static std::uniform_int_distribution<> dis;
        return dis(e);
    }

    float RandomNum::getRandomFloat()
    {
        static std::default_random_engine e;
        static std::uniform_real_distribution<> dis;
        return (float)dis(e);
    }

}  // namespace Engine
