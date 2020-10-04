#pragma once

#include <vector>
#include "cell.hpp"

class Grid {

	private:

		std::vector < std::vector <cell> > grid;

	public:

		Grid();
		~Grid();
		void draw(sf::RenderWindow &window) const;
		std::pair <int, int> checkClick(const sf::Vector2i &clickCoords) const;
		void setNumber(const int &row, const int &col, const int &number);
		int getNumber(const int &row, const int &col) const;
		void setCellTextColor(const int &row, const int &col, const sf::Color &color);
		void setCellGenerated(const int &row, const int &col, const bool &gen);
		bool getCellGenerated(const int &row, const int &col) const;
};