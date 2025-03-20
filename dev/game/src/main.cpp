#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.h"
#include "constants.h"
#include <components/SpriteRenderer.h>
#include <components/RectCollider.h>
#include <PlayerMovement.h>


int main()
{

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::Event event;
    
    Texture playerTexture;
    playerTexture.loadFromFile(SPRITE_PATH + "hero.png");

    Texture groundTexture;
    groundTexture.loadFromFile(SPRITE_PATH + "test.png");



    GameObject* player = new GameObject("Player");

    player->AddComponent(new SpriteRenderer(playerTexture));
    player->AddComponent(new PlayerMovement());
    player->AddComponent(new RectCollider(sf::FloatRect(0, 0, 64, 64)) );

    player->setPosition(200, 200);


    GameObject* floor = new GameObject("Floor");
    
   
    floor->AddComponent(new SpriteRenderer(groundTexture));
    floor->AddComponent(new RectCollider(sf::FloatRect(0, 10, 444, 140)) );

    
    floor->setPosition(100, 300);

  



    Scene level_1;
    level_1.name = "adasdad";

    level_1.AddObject(floor);
    level_1.AddObject(player);
  

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        level_1.Update();

        level_1.UpdateCollision();
    

        level_1.Render(window);
     
        


        window.display();
    }
    

  
}
