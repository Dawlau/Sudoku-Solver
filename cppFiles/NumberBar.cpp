#include "NumberBar.hpp"
#include "constants.hpp"
#include <iostream>


NumberBar::NumberBar() {

	buttons.reserve(numbersCount);
	for(int idx = 0; idx < numbersCount; ++idx){

		buttons.push_back(NumberButton(

			width / numbersCount - 5,
			idx * (width / numbersCount),
			width - (width / numbersCount),
			(idx == 0 ? "Del" : std::to_string(idx))
		));
	}
}


void NumberBar::draw(sf::RenderWindow &window) const{

	int i = -1;
	for(int idx = 0; idx < (int)buttons.size(); ++idx)
		if(buttons[idx].getRect().getOutlineColor() == sf::Color::Green){

			i = idx;
			break;
		}

	if(i == -1){
		for(int idx = 0; idx < (int)buttons.size(); ++idx)
			buttons[idx].draw(window);
		return;
	}

	for(int idx = 0; idx < i; ++idx)
		buttons[idx].draw(window);
	for(int idx = i + 1; idx < (int)buttons.size(); ++idx)
		buttons[idx].draw(window);

	buttons[i].draw(window);
}


int NumberBar::checkClick(const sf::Vector2i &clickCoords) const{

	for(int idx = 0; idx < (int)buttons.size(); ++idx)
		if(buttons[idx].isClicked(clickCoords))
			return idx;
	return -1;
}


void NumberBar::changeOutlineColor(const int &idx, const sf::Color &color){
	buttons[idx].changeOutlineColor(color);
}


NumberBar::~NumberBar() {}
