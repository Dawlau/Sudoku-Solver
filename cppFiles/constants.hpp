#pragma once

#include <string>
#include "SFML/Graphics.hpp"


// window related constants
const int width = 600;
const int height = 600;
const std::string Title = "Sudoku solver";


// colors
const sf::Color white = sf::Color(255, 255, 255, 255);
const sf::Color black = sf::Color(0, 0, 0, 255);

// grid related constants

const int gridSize = 9;
const int cellSize = 20; //px