#pragma once


#include "Grid.hpp"
#include <vector>
#include "constants.hpp"


class Generator{

	private:

		struct Candidates {

			int row, col;
			std::vector <int> candidates;
		};
		static std::vector <long long> fact;
		static int calls;

		static bool generated;
		static void fillGrid(Grid &grid);
		static std::vector <Generator::Candidates> getEmptyCells(Grid &grid);
		static void fillTopLayer(Grid &grid);
		static void fillFirstSquare(Grid &grid);
		static void fillSecondSquare(Grid &grid);
		static void fillThirdSquare(Grid &grid);
		static std::vector <int> getKthPermutation(int n, int k);
		static void buildFact(const int &n);
		static void shuffle(Grid &grid, const int &row, const int &start, const int &stop);
		static void finishGrid(Grid &grid);


	public:

		static void generate(Grid &grid);
};