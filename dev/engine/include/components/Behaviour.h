#pragma once

#include "Component.h"
#include <iostream>
#include "SpriteRenderer.h"
#include "components/RectCollider.h"

class Behaviour : public Component
{
	
public:

	virtual void Start() {};
	virtual void Update() {};
	virtual void OnCollision(RectCollider*  other) {};

};


