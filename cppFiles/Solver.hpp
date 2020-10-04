#pragma once

#include "constants.hpp"
#include "eventHandler.hpp"
#include "Grid.hpp"



class Solver{

	private:

		static void Backtracking(Grid &grid, const int &row, const int &col, sf::RenderWindow &window);
		static std::pair <int, int> nextCell(const int &row, const int &col);

		static bool Done;

	public:

		Solver();
		~Solver();

		static void solve(Grid &grid, sf::RenderWindow &window);
};