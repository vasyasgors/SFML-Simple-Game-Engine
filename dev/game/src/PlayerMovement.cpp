#include "PlayerMovement.h"
#include <GameObject.h>
#include <components/SpriteRenderer.h>
#include <Scene.h>

void PlayerMovement::Start()

{

}

void PlayerMovement::OnCollision(RectCollider* other)
{
	std::cout << other->gameObject->name << std::endl;
}

void PlayerMovement::Update() 
{
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{

		FloatRect rect(gameObject->getPosition().x, gameObject->getPosition().y + 64, 1, 1);


	//	std::cout << rect.getPosition().x << "  " << rect.getPosition().y << " " << gameObject->scene->BoxCast(rect) << std::endl;


		if (gameObject->scene->BoxCast(rect) == false)
		{
			gameObject->move(0, 0.1f);
		}


	

		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		gameObject->move(0, -0.1f);
	}








	

}