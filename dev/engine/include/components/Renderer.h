#pragma once

#include <SFML/Graphics.hpp>
#include "components/Component.h"

class Renderer : public Component
{
public:
	virtual void Render(sf::RenderWindow* window) {};
	virtual void SyncTransform() {};
};

