#include <iostream>

#include "Application.h"
#include "Engine.h"
#include "Mono.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Engine::InitEngine();

    Engine::Application app;
    app.Run();

    Engine::CreateDomain();

    return 0;
}
