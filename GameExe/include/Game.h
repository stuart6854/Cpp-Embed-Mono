//
// Created by stumi on 11/11/21.
//

#ifndef _EMBED_MONO_GAME_H
#define _EMBED_MONO_GAME_H

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

namespace Game
{
    class Game
    {
    public:
        Game();
        ~Game();

        void keyEvent(char key);
        bool tick();

    private:
        // Mono generic stuff
        MonoDomain* monoDomain = nullptr;
        MonoAssembly* gameAssembly = nullptr;
        MonoImage* gameAssemblyImage = nullptr;
        MonoObject* gameObject = nullptr;
        uint32_t gameObjectGCHandle;

        MonoMethod* tickMethod = nullptr;
        MonoMethod* keyEventMethod = nullptr;
    };
}  // namespace Game

#endif  //_EMBED_MONO_GAME_H
