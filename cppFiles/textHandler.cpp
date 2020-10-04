#include "textHandler.hpp"
#include "constants.hpp"
#include <iostream>


textHandler::textHandler(){

	setText(quitText, sf::Vector2f(0, 0));

	setText(restartText, sf::Vector2f(

		0,
		texts[(int)texts.size() - 1].getGlobalBounds().top + texts[(int)texts.size() - 1].getGlobalBounds().height
	));

	setText(showsolutionText, sf::Vector2f(

		0,
		texts[(int)texts.size() - 1].getGlobalBounds().top + texts[(int)texts.size() - 1].getGlobalBounds().height
	));
}



void textHandler::setText(const std::string &String, const sf::Vector2f &pos){

	sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(pxTextSize);
    text.setString(String);
	text.setPosition(pos);

	texts.push_back(text);
}


void textHandler::draw(sf::RenderWindow &window) const{

	for(int idx = 0; idx < (int)texts.size(); ++idx)
		window.draw(texts[idx]);
}


textHandler::~textHandler(){}