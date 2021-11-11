#include <iostream>

// Game includes
#include "Game.h"

// Engine Includes
#include "Application.h"
#include "Engine.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    Engine::InitEngine();

    Engine::Application app;
    app.Run();

    Game::Game game;

    while(true)
    {
        game.keyEvent('f');
        game.tick();
    }

    return 0;
}
