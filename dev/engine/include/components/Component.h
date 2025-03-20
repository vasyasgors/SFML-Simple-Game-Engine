#pragma once

class GameObject;

class Component 
{
	
public:
	Component();
	virtual ~Component() = default;

	GameObject* gameObject;
	bool enabled;
};
