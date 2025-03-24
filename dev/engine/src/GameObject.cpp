#include "GameObject.h"




GameObject::GameObject()
{
	active = true;
	this->name = "GameObject";
	this->tag = "Untagged";
}

GameObject:: GameObject(std::string name)
{
	active = true;
	this->name = name;
	this->tag = "Untagged";
}

GameObject::GameObject(std::string name, std::string tag)
{
	active = true;
	this->name = name;
	this->tag = tag;
}

GameObject::~GameObject()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}