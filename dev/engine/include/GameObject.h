﻿#pragma once

#include <string>


#include "components/Behaviour.h"
#include "components/Renderer.h"
#include "components/Component.h"


class Scene;

class GameObject : public sf::Transformable
{
	
public:
	GameObject();
	GameObject(std::string name);
	GameObject(std::string name, std::string tag);
	~GameObject();

	template <typename T>
	void AddComponent(T* component)
	{
		components.push_back(component);

		Component* newComponent = dynamic_cast<Component*>(component);
		newComponent->gameObject = this;
	}

	template <typename T>
	T* GetComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (T* component = dynamic_cast<T*>(components[i]))
			{
				return component;
			}
		}
		return nullptr;
	}

	template <typename T>
	std::vector<T*> GetComponents()
	{
		std::vector<T*> result;

		for (size_t i = 0; i < components.size(); i++)
		{
			if (T* component = dynamic_cast<T*>(components[i]))
			{
				result.push_back(component);
			}
		}
		return result;
	}

	Scene* scene;
	std::string name;
	std::string tag;
	
	bool active;
	int instanceId;

private:
	std::vector<Component*> components;

};

