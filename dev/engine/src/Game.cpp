#include "Game.h"
#include <SFML/Graphics.hpp>

Game* CurrentGame;

Game::Game(sf::Vector2<int> windowSize, std::string windowTitle)
{
    this->mainWindow = new RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), windowTitle);
    this->mainWindow->setFramerateLimit(60);

    this->mainCamera = new View(sf::FloatRect(0, 0, mainWindow->getSize().x, mainWindow->getSize().y));

    CurrentGame = this;
}

Game::~Game()
{
    delete this->mainWindow;
}


void Game::StartGame(Scene* scene)
{
    CurrentGame->LoadedScene = scene;
    CurrentGame->LoadedScene->Start();

    sf::Event event;
    sf::Clock deltaClock;

    while (mainWindow->isOpen())
    {
        while (mainWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) mainWindow->close();

            if (event.type == sf::Event::Resized)
            {
                 mainCamera->setSize(mainWindow->getSize().x, mainWindow->getSize().y);
            }
        }

        mainWindow->clear();

        mainWindow->setView(*mainCamera);

        if (LoadedScene != nullptr)
        {
            LoadedScene->Update();
            LoadedScene->UpdateCollision();
            LoadedScene->Render(*mainWindow);
        }

        mainWindow->display();

        this->deltaTime = deltaClock.restart().asSeconds();
    }

}






void LoadScene(Scene* scene)
{
    CurrentGame->LoadedScene = scene;
    CurrentGame->LoadedScene->Start();
}