#pragma once


#include <SFML/Graphics.hpp>

#include "components/Component.h"

class RectCollider : public Component
{

public:

	RectCollider(sf::FloatRect rect);

	void SyncTransform();


	sf::FloatRect rect;

private:
	sf::FloatRect defaultRect;
};

