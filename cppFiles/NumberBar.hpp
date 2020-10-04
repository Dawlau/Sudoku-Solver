#pragma once

#include <vector>
#include "NumberButton.hpp"

class NumberBar {

	private:

	std::vector <NumberButton> buttons;

	public:

		NumberBar();
		~NumberBar();
		void draw(sf::RenderWindow &window) const;
		int checkClick(const sf::Vector2i &clickCoords) const;
		void changeOutlineColor(const int &idx, const sf::Color &color);
};