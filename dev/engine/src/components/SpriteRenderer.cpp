#include "components/SpriteRenderer.h"
#include "GameObject.h"

SpriteRenderer::SpriteRenderer(sf::Texture& texture)
{
	sprite.setTexture(texture);
	enabled = true;
	collided = true;
}

SpriteRenderer::SpriteRenderer(std::string texturePath)
{
	this->texture = new sf::Texture();
	this->texture->loadFromFile(texturePath);
	sprite.setTexture(*(this->texture));

	enabled = true;
	collided = true;
}

SpriteRenderer::~SpriteRenderer()
{
	delete this->texture;
}


void SpriteRenderer::SyncTransform()
{
	sprite.setPosition(gameObject->getPosition());
	sprite.setRotation(gameObject->getRotation());
	sprite.setScale(gameObject->getScale());
	sprite.setOrigin(gameObject->getOrigin());
}


void SpriteRenderer::Render(sf::RenderWindow* window) 
{
	
	window->draw(sprite);
}

