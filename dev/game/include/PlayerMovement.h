#pragma once

#include "components/Behaviour.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

class PlayerMovement : public Behaviour 
{
public:

	~PlayerMovement();

	void Update() override;
	void Start() override;
	void OnCollision(RectCollider* other) override;

	

};

