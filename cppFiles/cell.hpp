#pragma once

#include "SFML/Graphics.hpp"


class cell
{
	private:
		int row, col, number;

	public:

		cell(const int &, const int &, const int &);
		~cell();
		void draw(sf::RenderWindow &) const;
};