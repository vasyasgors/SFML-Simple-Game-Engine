#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.h"
#include "constants.h"
#include <components/SpriteRenderer.h>
#include <components/RectCollider.h>
#include <PlayerMovement.h>
#include "Game.h"


int main()
{

     
    Texture playerTexture;
    playerTexture.loadFromFile(SPRITE_PATH + "hero.png");
    playerTexture.setSmooth(true);

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

   
    Game game({ 800, 600 }, "Redball");

    Game::mainCamera->setCenter(player->getPosition().x, player->getPosition().y);



 


 


    game.StartGame(&level_1);
   
  

  
}
