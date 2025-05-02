#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.h"
#include "constants.h"
#include <components/SpriteRenderer.h>
#include <components/RectCollider.h>
#include <components/TextRenderer.h>
#include <PlayerMovement.h>
#include "Game.h"


int main()
{

    
    GameObject* player = new GameObject("Player");
    player->AddComponent(new SpriteRenderer(SPRITE_PATH + "hero.png"));
    player->AddComponent(new PlayerMovement());
    player->AddComponent(new RectCollider(sf::FloatRect(0, 0, 64, 64)) );

    player->setPosition(0, 0);

    GameObject* testText = new GameObject();

    Vector2f t2(0, 0);

    int t3 = 34;


    TextRenderer* t = new TextRenderer("arial.ttf", {0, 0}, "score: " +  std::to_string(t3));

    testText->AddComponent(t);


    GameObject* floor = new GameObject("Floor");
    
   
    floor->AddComponent(new SpriteRenderer(SPRITE_PATH + "test.png"));
    floor->AddComponent(new RectCollider(sf::FloatRect(0, 10, 444, 140)) );

    
    floor->setPosition(100, 300);
    floor->setScale(0.3f, 0.3f);

  


    
    Scene level_1;
    level_1.showColliders = true;
    level_1.name = "adasdad";
    //level_1.backgroundColor = sf::Color(153, 217, 234);

    level_1.AddObject(floor);
    level_1.AddObject(player);
    level_1.AddObject(testText);

   
    Game game({ 800, 600 }, "Redball");

    Game::mainCamera->setCenter(player->getPosition().x, player->getPosition().y);



    game.StartGame(&level_1);
   
  

  
}
