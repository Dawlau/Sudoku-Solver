#pragma once
#include "SFML/Graphics.hpp"
#include "NumberBar.hpp"
#include "Grid.hpp"
#include "Solver.hpp"


class eventHandler {

	private:

		sf::RenderWindow *window;
		NumberBar *bar;
		Grid *grid;
		int *selectedNumber;
		mutable bool violation;
		mutable std::pair <int, int> redCell;


		void handleKeyboard() const;
		void handleMouse(sf::Vector2i &clickCoords) const;

	public:

		eventHandler();
		eventHandler(sf::RenderWindow *window, NumberBar *bar, Grid *grid, int *selectedNumber);
		~eventHandler();
		void handle() const;
		void restartGame() const;
		static bool checkViolation(Grid &grid);
		static bool checkRowViolation(Grid &grid);
		static bool checkColViolation(Grid &grid);
		static bool checkSquareViolation(Grid &grid);
		static bool checkEnd(Grid &grid);
};