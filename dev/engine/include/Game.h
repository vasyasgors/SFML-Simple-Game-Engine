#pragma once

#include "Scene.h"
#include <SFML/System/Vector2.hpp>

class Game
{

public:
	
	Game(sf::Vector2<int> windowSize, std::string windowTitle);
	~Game();


	void StartGame(Scene* scene);

	static inline float deltaTime{};
	static inline sf::View* mainCamera{};

	Scene* LoadedScene;

private:

	friend void LoadScene(Scene* scene);
	


	sf::RenderWindow* mainWindow;
};

extern Game* CurrentGame;

void LoadScene(Scene* scene);

