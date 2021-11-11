//
// Created by stumi on 11/11/21.
//

#include "Mono.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

namespace Engine {
    void CreateDomain() {
        // Point to mono libs
        mono_set_dirs(".", ".");
        auto m = mono_init("GameExe.exe");
    }
}// namespace Engine