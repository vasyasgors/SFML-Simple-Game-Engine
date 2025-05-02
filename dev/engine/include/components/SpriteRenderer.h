#pragma once

#include <SFML/Graphics.hpp>
#include "components/Renderer.h"

class SpriteRenderer : public Renderer
{

public:
	SpriteRenderer(sf::Texture& texture);
	SpriteRenderer(std::string texturePath);
	~SpriteRenderer();
	

	void Render(sf::RenderWindow* window) override;
	void SyncTransform() override;

	sf::Sprite sprite;
	bool collided;

private:
	sf::Texture* texture;

};
