#include "cell.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"


cell::cell(const int &row, const int &col, const int &number){

	this->row = row;
	this->col = col;
	this->number = number;
}

void cell::draw(sf::RenderWindow &window) const{

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(cellSize, cellSize));
	rect.setOutlineColor(black);
	rect.setOutlineThickness(1);

	int pxGridSize = cellSize * gridSize;

	int XoffSet = width / 2 - pxGridSize / 2;
	int YoffSet = height / 2 - pxGridSize / 2;

	int x = row * cellSize + XoffSet;
	int y = col * cellSize + YoffSet;

	rect.setPosition(sf::Vector2f(x, y));

	window.draw(rect);
}

cell::~cell() {}