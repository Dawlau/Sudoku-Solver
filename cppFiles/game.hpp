#pragma once

#include "SFML/Graphics.hpp"
#include "cell.hpp"
#include <vector>


class game{

	private:

		sf::RenderWindow window;
		std::vector< std::vector <cell> > grid;

	public:

		game();

		void run();
		void handleEvents();
		void drawGrid();
		void restartGame();
		void drawControls();

		~game();

};