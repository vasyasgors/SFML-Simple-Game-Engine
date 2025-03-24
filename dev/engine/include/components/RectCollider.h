#pragma once


#include <SFML/Graphics.hpp>

#include "components/Component.h"

class RectCollider : public Component
{

public:

	RectCollider(sf::FloatRect rect);

	void SyncTransform();
	void Render(sf::RenderWindow* window);


	sf::FloatRect rect;

private:
	sf::FloatRect defaultRect;
};

