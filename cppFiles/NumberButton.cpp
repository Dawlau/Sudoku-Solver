#include "NumberButton.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include <iostream>


NumberButton::NumberButton(const int &sideSize = 0, const int &xPos = 0, const int &yPos = 0, const std::string &txt = "") : sideSize(sideSize), xPos(xPos), yPos(yPos) {


	initRect();
	initText(txt);
}



void NumberButton::initText(const std::string &s){

	text.setFont(font);
	text.setString(s);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(sideSize / 2);


	text.setPosition(sf::Vector2f(

		xPos + (sideSize) / (s == "Del" ? 6 : 2.5),
		yPos
	));

	this->text = text;
}



void NumberButton::initRect(){

	sf::RectangleShape rect;

	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(3);
	rect.setSize(sf::Vector2f(

		sideSize,
		sideSize
	));
	rect.setPosition(sf::Vector2f(

		xPos + 3,
		yPos - 10
	));

	this->rect = rect;
}



void NumberButton::changeOutlineColor(const sf::Color &color){
	rect.setOutlineColor(color);
}



void NumberButton::draw(sf::RenderWindow &window) const{
	window.draw(rect);
	window.draw(text);
}



NumberButton::~NumberButton() {}