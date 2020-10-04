#pragma once
#include "SFML/Graphics.hpp"

class Rectangle {


	protected:
		sf::RectangleShape rect;

	public:

		Rectangle(){}
		Rectangle(const sf::RectangleShape &rect);
		~Rectangle();
		bool isClicked(const sf::Vector2i &clickCoords) const;
		sf::RectangleShape getRect() const;
		void drawInto(sf::RenderWindow &window);
		void setRect(sf::RectangleShape &rect);
		Rectangle& operator =(const Rectangle &other);
};