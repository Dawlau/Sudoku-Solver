#pragma once

#include "SFML/Graphics.hpp"

class game
{
	private:
		sf::RenderWindow window;

	public:

		game();

		void run();
		void handleEvents();

		~game();

};