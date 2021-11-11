#include <iostream>

#include "Application.h"
#include "Engine.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Engine::InitEngine();

    Engine::Application app;
    app.Run();

    return 0;
}
