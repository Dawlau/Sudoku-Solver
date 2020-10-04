#include "Generator.hpp"
#include "Grid.hpp"
#include <vector>
#include <algorithm>
#include "constants.hpp"
#include <iostream>
#include "eventHandler.hpp"
#include <ctime>
#include <random>

bool Generator::generated;
int Generator:: calls;
std::vector <long long> Generator::fact;


std::random_device rand_dev;
std::mt19937       generator(rand_dev());



void Generator::buildFact(const int &n){

	fact.resize(n);

	fact[0] = 1;
	for(int i = 1; i < n; ++i)
		fact[i] = fact[i - 1] * i;
}




void Generator::fillTopLayer(Grid &grid){

	fillFirstSquare(grid);
	fillSecondSquare(grid);
	fillThirdSquare(grid);
}





void Generator::generate(Grid &grid){

	Generator::generated = false;

	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col){

			grid.setCellGenerated(row, col, true);
			grid.setCellTextColor(row, col, sf::Color::Black);
		}

	buildFact(numbersCount);

	fillTopLayer(grid);
	calls = 0;
	fillGrid(grid);
	finishGrid(grid);
}





void Generator::finishGrid(Grid &grid){

	int cnt = 0;
	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col)
			if(grid.getNumber(row, col) == 0)
				++cnt;

	std::uniform_int_distribution <int>  distr(0, gridSize - 1);
	while(cnt < 50){

		int row = distr(generator);
		int col = distr(generator);

		if(grid.getNumber(row, col)){
			++cnt;
			grid.setNumber(row, col, 0);
		}
	}

	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col)
			if(grid.getNumber(row, col) == 0){

				grid.setCellGenerated(row, col, false);
				grid.setCellTextColor(row, col, sf::Color::Blue);
			}
}



std::vector <int> Generator::getKthPermutation(int n, int k){

	--k;

	std::vector <int> perm(n);
	for(int i = 0; i < n; ++i)
		perm[i] = i + 1;

	std::vector <int> res;
    res.reserve(n);

    for(--n; n >= 0; --n){

        long long f = fact[n];
        res.push_back(perm[k / f]);

        for(int i = k / f; i < n; ++i)
            perm[i] = perm[i + 1];

        k %= f;
    }

	return res;
}


void Generator::shuffle(Grid &grid, const int &row, const int &start, const int &stop){

	for(int idx = start + 1; idx != stop; ++idx){
		std::uniform_int_distribution <int>  distr(start, idx - 1);
		int i = distr(generator);

		int aux = grid.getNumber(row, i);
		grid.setNumber(row, i, grid.getNumber(row, idx));
		grid.setNumber(row, idx, aux);
	}
}


void Generator::fillFirstSquare(Grid &grid){

	std::uniform_int_distribution <int>  distr(1, fact[numbersCount - 1]);
	int k = distr(generator);

	std::vector <int> perm = getKthPermutation(numbersCount - 1, k);

	int idx = 0;
	for(int row = 0; row < 3; ++row)
		for(int col = 0; col < 3; ++col)
			grid.setNumber(row, col, perm[idx++]);
}


void Generator::fillSecondSquare(Grid &grid){

	// first row
	for(int col = 3; col < 6; ++col)
		grid.setNumber(0, col, grid.getNumber(1, col - 3));

	// second row
	for(int col = 3; col < 6; ++col)
		grid.setNumber(1, col, grid.getNumber(2, col - 3));

	// third row
	for(int col = 3; col < 6; ++col)
		grid.setNumber(2, col, grid.getNumber(0, col - 3));

	shuffle(grid, 0, 3, 6);
	shuffle(grid, 1, 3, 6);
	shuffle(grid, 2, 3, 6);
}


void Generator::fillThirdSquare(Grid &grid){

	std::vector <int> freq(numbersCount);

	// first row

	for(int col = 0; col < 6; ++col)
		++freq[grid.getNumber(0, col)];

	int c = 6;
	for(int no = 1; no < numbersCount; ++no)
		if(freq[no] == 0)
			grid.setNumber(0, c++, no);

	std::fill(freq.begin(), freq.end(), 0);

	// second row

	for(int col = 0; col < 6; ++col)
		++freq[grid.getNumber(1, col)];

	c = 6;
	for(int no = 1; no < numbersCount; ++no)
		if(freq[no] == 0)
			grid.setNumber(1, c++, no);


	std::fill(freq.begin(), freq.end(), 0);

	// third row

	for(int col = 0; col < 6; ++col)
		++freq[grid.getNumber(2, col)];

	c = 6;
	for(int no = 1; no < numbersCount; ++no)
		if(freq[no] == 0)
			grid.setNumber(2, c++, no);
}








void Generator::fillGrid(Grid &grid){
	++calls;

	if(calls > 1e5){
		Generator::generated = true;
		return ;
	}

	if(Generator::generated)
		return ;


	if(eventHandler::checkEnd(grid)){

		Generator::generated = true;
		return ;
	}



	std::vector < Candidates > emptyCells = getEmptyCells(grid);

	if(emptyCells.size() == 0){
		return ;
	}

	std::sort(emptyCells.begin(), emptyCells.end(),
	[&](const Candidates &a, const Candidates &b){
		return a.candidates.size() < b.candidates.size();
	});

	Candidates c = emptyCells[0];
	int row = c.row;
	int col = c.col;


	while(!c.candidates.empty() and !Generator::generated){

		std::uniform_int_distribution <int>  distr(0, c.candidates.size() - 1);
		int idx = distr(generator);

		grid.setNumber(row, col, c.candidates[idx]);
		c.candidates.erase(c.candidates.begin() + idx);
		fillGrid(grid);


		if(!Generator::generated)
			grid.setNumber(row, col, 0);
	}
}







std::vector <Generator::Candidates> Generator::getEmptyCells(Grid &grid){

	std::vector <Candidates> emptyCells;

	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col)
			if(grid.getNumber(row, col) == 0){

				std::vector <int> freq(numbersCount);

				// scan column

				for(int r = 0; r < row; ++r)
					++freq[grid.getNumber(r, col)];
				for(int r = row + 1; r < gridSize; ++r)
					++freq[grid.getNumber(r, col)];

				// scan row

				for(int c = 0; c < col; ++c)
					++freq[grid.getNumber(row, c)];
				for(int c = col + 1; c < gridSize; ++c)
					++freq[grid.getNumber(row, c)];

				// scan square

				int R = row / 3 * 3;
				int C = col / 3 * 3;

				for(int r = R; r < R + 3; ++r)
					for(int c = C; c < C + 3; ++c)
						++freq[grid.getNumber(r, c)];


				std::vector <int> candidates;
				for(int no = 1; no < numbersCount; ++no)
					if(freq[no] == 0)
						candidates.push_back(no);

				if(candidates.size())
					emptyCells.push_back({row, col, candidates});
			}

	return emptyCells;
}