#include "Grid.hpp"
#include <vector>
#include "cell.hpp"

Grid::Grid() {

	grid = std::vector < std::vector <cell> >(gridSize, std::vector <cell> (gridSize));

	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col)
			grid[row][col] = cell(row, col, 0);
}


void Grid::draw(sf::RenderWindow &window) const{

	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col)
			grid[row][col].draw(window);


	for (int row = 0; row < gridSize; row += 3)
        for (int col = 0; col < gridSize; col += 3){

            sf::RectangleShape rect;

            rect.setSize(sf::Vector2f(
				3 * pxCellSize,
				3 * pxCellSize
			));

            rect.setOutlineColor(sf::Color::Black);
            rect.setFillColor(sf::Color::Transparent);


            int pxGridSize = pxCellSize * gridSize;

            int XoffSet = width / 2 - pxGridSize / 2;
            int YoffSet = height / 2 - pxGridSize / 2;

            rect.setPosition(sf::Vector2f(
				col * pxCellSize + XoffSet,
				row * pxCellSize + YoffSet
			));

			rect.setOutlineThickness(2);
            window.draw(rect);

            rect.setOutlineThickness(-2);
            window.draw(rect);
        }
}


std::pair <int, int> Grid::checkClick(const sf::Vector2i &clickCoords) const{

	for(int row = 0; row < gridSize; ++row)
		for(int col = 0; col < gridSize; ++col)
			if(grid[row][col].isClicked(clickCoords))
				return {row, col};
	return {-1, -1};
}


void Grid::setNumber(const int &row, const int &col, const int &number){
	grid[row][col].setNumber(number);
}


int Grid::getNumber(const int &row, const int &col) const{

	if(row < 0 or row >= gridSize or col < 0 or col >= gridSize)
		return 0;

	return grid[row][col].getNumber();
}



void Grid::setCellTextColor(const int &row, const int &col, const sf::Color &color){
	grid[row][col].setTextColor(color);
}



void Grid::setCellGenerated(const int &row, const int &col, const bool &gen){
	grid[row][col].setGenerated(gen);
}


bool Grid::getCellGenerated(const int &row, const int &col) const{
	return grid[row][col].getGenerated();
}



Grid::~Grid() {}