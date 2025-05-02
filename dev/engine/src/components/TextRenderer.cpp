#include "components/TextRenderer.h"
#include <iostream>

TextRenderer::TextRenderer(std::string font, sf::Vector2f position, std::string text)
{
	this->font.loadFromFile(font);
	this->position = position;
	this->text = text;

	this->textObject = new sf::Text();
	this->textObject->setFont(this->font);
	this->textObject->setString(text);
	this->textObject->setPosition(position);


}

TextRenderer::~TextRenderer()
{
	delete this->textObject;
}

void TextRenderer::Render(sf::RenderWindow* window)
{
	sf::Vector2f viewCenter = window->getView().getCenter();
	sf::Vector2f anchor(viewCenter.x - window->getView().getSize().x * 0.5f, viewCenter.y - window->getView().getSize().y * 0.5f);

	this->textObject->setPosition(anchor + position);

	window->draw(*this->textObject);
}


