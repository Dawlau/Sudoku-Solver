#include "cell.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "constants.hpp"


cell::cell(const int &row = 0, const int &col = 0, const int &number = 0){

	this->number = number;
	generated = false;

	initRect(row, col);
	initText();
}

void cell::initRect(const int &row, const int &col){

	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(pxCellSize, pxCellSize));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(-1);

	int pxGridSize = pxCellSize * gridSize;

	int XoffSet = width / 2 - pxGridSize / 2;
	int YoffSet = height / 2 - pxGridSize / 2;

	int x = col * pxCellSize + XoffSet;
	int y = row * pxCellSize + YoffSet;

	rect.setPosition(sf::Vector2f(x, y));

	this->rect = rect;
}

void cell::initText(){

	text.setFont(font);
	text.setFillColor(sf::Color::Blue);
	text.setCharacterSize(pxCellSize);

	sf::Vector2f coords = rect.getPosition();
	text.setPosition(sf::Vector2f(
									coords.x + pxCellSize / 5,
									coords.y - pxCellSize / 8
								 ));

	text.setString(std::to_string(number));
}


void cell::draw(sf::RenderWindow &window) const{
	window.draw(rect);
	if(number) window.draw(text);
}


int cell::getNumber() const{
	return number;
}

void cell::setNumber(const int &number){
	this->number = number;
	text.setString(std::to_string(number));
}


void cell::setTextColor(const sf::Color &color){
	text.setFillColor(color);
}


void cell::setGenerated(const bool &gen){
	generated = gen;
}


bool cell::getGenerated() const{
	return generated;
}


cell::~cell() {}