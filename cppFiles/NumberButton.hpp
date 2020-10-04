#pragma once

#include "Rectangle.hpp"
#include "SFML/Graphics.hpp"
#include <string>

class NumberButton : public Rectangle{

	private:

		sf::Text text;
		int sideSize;
		int xPos;
		int yPos;

		void initText(const std::string &);
		void initRect();

	public:

		NumberButton(const int &sideSize, const int &xPos, const int &yPos, const std::string &txt);
		~NumberButton();
		void changeOutlineColor(const sf:: Color &);
		void draw(sf::RenderWindow &) const;

};
