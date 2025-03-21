#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "Game.h"
#include <components/Renderer.h>
#include <components/SpriteRenderer.h>
#include <components/RectCollider.h>

using namespace sf;

Scene::Scene()
{
	instanceId = 0;
}

void Scene::AddObject(GameObject* object)
{
    objects.push_back(object);

    object->scene = this;
    object->instanceId = instanceId;

    instanceId++;

    if (CurrentGame == nullptr) return; // вызываем только во время игры
	
    std::vector<Behaviour*> behaviours = object->GetComponents<Behaviour>();

    for (size_t i = 0; i < behaviours.size(); i++)
    {
        if (behaviours[i]->enabled == false) continue;

        behaviours[i]->Start();
    }


    std::vector<SpriteRenderer*> spriteRenderers = object->GetComponents<SpriteRenderer>();

    for (size_t i = 0; i < spriteRenderers.size(); i++)
    {
        if (spriteRenderers[i]->enabled == false) continue;

        spriteRenderers[i]->SyncTransform();
    }

    std::vector<RectCollider*> rectColliders = object->GetComponents<RectCollider>();

    for (size_t i = 0; i < rectColliders.size(); i++)
    {
        if (rectColliders[i]->enabled == false) continue;

        rectColliders[i]->SyncTransform();
    }
}

void Scene::Start()
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == false) continue;

        // sync colliders
        std::vector<RectCollider*> rectColliders = objects[i]->GetComponents<RectCollider>();

        for (size_t j = 0; j < rectColliders.size(); j++)
        {
            if (rectColliders[j]->enabled == false) continue;

            rectColliders[j]->SyncTransform();
        }



        // sync renderers
        std::vector<Renderer*> renderers = objects[i]->GetComponents<Renderer>();

        for (size_t j = 0; j < renderers.size(); j++)
        {
            if (renderers[j]->enabled == false) continue;

            renderers[j]->SyncTransform();
        }

        // update behaciour
        std::vector<Behaviour*> behaviours = objects[i]->GetComponents<Behaviour>();

        for (size_t j = 0; j < behaviours.size(); j++)
        {
            if (behaviours[j]->enabled == true)
                behaviours[j]->Start();
        }
    }
}



void Scene::RemoveObject(GameObject* object)
{
    int id = object->instanceId;

    auto newEnd = std::remove_if(objects.begin(), objects.end(),
        [id](GameObject* obj) {
            return obj->instanceId == id;
        });

    objects.erase(newEnd, objects.end());

    delete object;
}

// Как-то это все более правильно написать
void Scene::Render(RenderWindow &window)
{
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == false) continue;

        std::vector<Renderer*> renderers = objects[i]->GetComponents<Renderer>();

        for (size_t i = 0; i < renderers.size(); i++)
        {
            if (renderers[i]->enabled == false) continue;

            renderers[i]-> Render(&window);
        }
    }

       
}

void Scene::Update()
{

    for (size_t i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == false) continue;

        // sync colliders
        std::vector<RectCollider*> rectColliders = objects[i]->GetComponents<RectCollider>();

        for (size_t j = 0; j < rectColliders.size(); j++)
        {
            if (rectColliders[j]->enabled == false) continue;

            rectColliders[j]->SyncTransform();
        }

      

        // sync renderers
        std::vector<Renderer*> renderers = objects[i]->GetComponents<Renderer>();

        for (size_t j = 0; j < renderers.size(); j++)
        {
            if (renderers[j]->enabled == false) continue;

            renderers[j]->SyncTransform();
        }

        // update behaciour
        std::vector<Behaviour*> behaviours = objects[i]->GetComponents<Behaviour>();

        for (size_t j = 0; j < behaviours.size(); j++)
        {
			if(behaviours[j]->enabled == true)
				behaviours[j]->Update();
        }
    }
}

bool Scene::BoxCast(FloatRect rect)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == false) continue;

        RectCollider* rectCollider = objects[i]->GetComponent<RectCollider>();

        if (rectCollider == nullptr) continue;

        if (rectCollider->enabled == false) continue;

        if (rectCollider->rect.intersects(rect) == true)
            return true;
    }

    return false;
}

// Если понадобиться, то запилить с учетом того, что может быть несколько спрайт ренедероров
void Scene::UpdateCollision()
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == false) continue;

        RectCollider* currentRectCollider = objects[i]->GetComponent<RectCollider>();

        if (currentRectCollider == nullptr) continue;

        if (currentRectCollider->enabled == false) continue;



        for (size_t j = 0; j < objects.size(); j++)
        {
            if (i == j) continue;

            RectCollider* otherRectCollider = objects[j]->GetComponent<RectCollider>();

            if (otherRectCollider == nullptr) continue;

            if (otherRectCollider->enabled == false) continue;

            if (currentRectCollider->rect.intersects(otherRectCollider->rect) == true)
            {

                Behaviour* currentBehaviour = objects[i]->GetComponent<Behaviour>();
                Behaviour* otherBehaviour = objects[j]->GetComponent<Behaviour>();


                if(currentBehaviour != nullptr)
                    currentBehaviour->OnCollision(otherRectCollider);

                if (otherBehaviour != nullptr)
                    otherBehaviour->OnCollision(currentRectCollider);
            }
        }
    }
}