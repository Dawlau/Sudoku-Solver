#pragma once

#include "SFML/Graphics.hpp"
#include "constants.hpp"

class game
{
	private:

		sf::RenderWindow window;
		int grid[gridSize][gridSize];



	public:

		game();

		void run();
		void handleEvents();
		void drawGrid();

		~game();

};