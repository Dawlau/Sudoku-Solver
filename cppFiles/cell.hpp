#pragma once

#include "SFML/Graphics.hpp"
#include "constants.hpp"


class cell{

	private:
		int row, col, number;
		sf::RectangleShape rect;

	public:
		cell(){}
		cell(const int &, const int &, const int &);
		~cell();
		void drawInto(sf::RenderWindow &);
		int getNumber() const;
		void setNumber(const int &);
};