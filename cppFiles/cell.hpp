#pragma once

#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include "Rectangle.hpp"


class cell : public Rectangle{

	private:
		int number;
		sf::Text text;
		bool generated;

		void initRect(const int &row, const int &col);
		void initText();

	public:
		cell(){}
		cell(const int &row, const int &col, const int &number);
		~cell();
		int getNumber() const;
		void setNumber(const int &number);
		void draw(sf::RenderWindow &window) const;
		void setTextColor(const sf::Color &color);
		void setGenerated(const bool &gen);
		bool getGenerated() const;
};