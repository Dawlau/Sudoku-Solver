#include "Solver.hpp"
#include <random>
#include "eventHandler.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <algorithm>


Solver::Solver(){}


bool Solver::Done;


void Solver::solve(Grid &grid, sf::RenderWindow &window){

	Solver::Done = false;

	Solver::Backtracking(grid, 0, 0, window);
}


std::pair <int, int> Solver::nextCell(const int &row, const int &col){

	std::pair <int, int> Next = {row, col};
	++Next.second;

	if(Next.second >= gridSize)
		Next.second = 0, ++Next.first;

	return Next;
}



void Solver::Backtracking(Grid &grid, const int &row, const int &col, sf::RenderWindow &window){


	if(eventHandler::checkEnd(grid)){

		Solver::Done = true;
		return ;
	}


	if(col >= gridSize or grid.getNumber(row, col)){   // already has number, go next

		std::pair <int, int> Next = nextCell(row, col);
		Backtracking(grid, Next.first, Next.second, window);
		return ;
	}


	for(int no = 1; no < numbersCount; ++no)
		if(!Solver::Done){

			grid.setNumber(row, col, no);

			grid.draw(window);
			window.display();
			usleep(55000);



			if(!eventHandler::checkViolation(grid)){

				std::pair <int, int> Next = nextCell(row, col);
				Backtracking(grid, Next.first, Next.second, window);
			}

			if(!Solver::Done) grid.setNumber(row, col, 0);
		}
}



Solver::~Solver(){}