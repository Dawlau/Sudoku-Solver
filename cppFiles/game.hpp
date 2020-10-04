#pragma once

#include "SFML/Graphics.hpp"
#include "cell.hpp"
#include "Rectangle.hpp"
#include <vector>
#include "Grid.hpp"
#include "NumberBar.hpp"
#include "eventHandler.hpp"
#include "textHandler.hpp"


class game{

	private:

		sf::RenderWindow window;
		NumberBar bar;
		Grid grid;
		int selectedNumber;
		eventHandler evHandler;
		textHandler txtHandler;

	public:

		game();

		void run();

		~game();

};