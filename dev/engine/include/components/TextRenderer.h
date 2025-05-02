#pragma once

#include <SFML/Graphics.hpp>
#include "components/Renderer.h"

class TextRenderer : public Renderer
{

public:
	TextRenderer(std::string font, sf::Vector2f position, std::string text);
	~TextRenderer();


	void Render(sf::RenderWindow* window) override;

	sf::Vector2f position;
	std::string text;
	sf::Text* textObject;
private:
	sf::Font font;
	
};