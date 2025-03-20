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