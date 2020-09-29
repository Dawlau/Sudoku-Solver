#include "cell.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "constants.hpp"


cell::cell(const int &row = 0, const int &col = 0, const int &number = 0)
{

	this->row = row;
	this->col = col;
	this->number = number;

	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(pxCellSize, pxCellSize));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1);

	int pxGridSize = pxCellSize * gridSize;

	int XoffSet = width / 2 - pxGridSize / 2;
	int YoffSet = height / 2 - pxGridSize / 2;

	int x = row * pxCellSize + XoffSet;
	int y = col * pxCellSize + YoffSet;

	rect.setPosition(sf::Vector2f(x, y));

	this->rect = rect;
}


void cell::drawInto(sf::RenderWindow &window){
	window.draw(rect);

	std::string no = std::to_string(this->number);

	sf::Text text;
	text.setFont(font);
	text.setString(no);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(pxTextSize);

	sf::FloatRect prototype = rect.getGlobalBounds();
	text.setPosition(sf::Vector2f(prototype.left + (pxCellSize - text.getGlobalBounds().width) / 2, prototype.top));


	window.draw(text);
}

cell::~cell() {}


int cell::getNumber() const{
	return number;
}

void cell::setNumber(const int &number){
	this->number = number;
}