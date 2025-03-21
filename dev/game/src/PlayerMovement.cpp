#include "PlayerMovement.h"
#include <GameObject.h>
#include <components/SpriteRenderer.h>
#include <Scene.h>
#include <Game.h>
#include <constants.h>

#include <SFML/Graphics.hpp>

void PlayerMovement::Start()
{

}

void PlayerMovement::OnCollision(RectCollider* other)
{
	//std::cout << other->gameObject->name << std::endl;
}

void PlayerMovement::Update() 
{
	
	//std::cout << Game::Instance()->deltaTime << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{

		FloatRect rect(gameObject->getPosition().x, gameObject->getPosition().y + 64, 1, 1);


	//	std::cout << rect.getPosition().x << "  " << rect.getPosition().y << " " << gameObject->scene->BoxCast(rect) << std::endl;
	
		
		if (gameObject->scene->BoxCast(rect) == false)
		{
			gameObject->move(0, 50 * Game::deltaTime);
		}


		Game::mainCamera->setCenter(gameObject->getPosition().x, gameObject->getPosition().y);

	

		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		gameObject->move(0, -50 * Game::deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{

	


		


	}








	

}