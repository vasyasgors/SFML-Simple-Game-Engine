#include "components/RectCollider.h"
#include "GameObject.h"

RectCollider::RectCollider(sf::FloatRect rect)
{
	this->defaultRect = rect;
	this->rect = rect;
}


void RectCollider::SyncTransform()
{
	rect = gameObject->getTransform().transformRect(defaultRect);
}

void RectCollider::Render(sf::RenderWindow* window)
{
	sf::RectangleShape rectangleShape;
	rectangleShape.setPosition(this->rect.getPosition());
	rectangleShape.setSize(this->rect.getSize());

	rectangleShape.getTransform().transformRect(this->rect);

	rectangleShape.setFillColor(sf::Color::Transparent);
	rectangleShape.setOutlineColor(sf::Color::Green);
	rectangleShape.setOutlineThickness(1);

	window->draw(rectangleShape);

}