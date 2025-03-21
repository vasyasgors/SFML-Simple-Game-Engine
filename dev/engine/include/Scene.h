#pragma once

#include <SFML/Graphics.hpp>
#include <GameObject.h>

using namespace sf;

class Scene
{

public:
    Scene();

    void AddObject(GameObject* object);
    void RemoveObject(GameObject* object);
    void Render(RenderWindow &window);  

    void Start();

    void UpdateCollision();
    void Update();
   
    bool BoxCast(FloatRect rect);
    std::string name;

private:
	int instanceId;
    std::vector<GameObject*> objects;
};
