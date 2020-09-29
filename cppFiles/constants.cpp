#include <string>
#include "SFML/Graphics.hpp"

// window related constants
int width = 600;
int height = 600;
std::string Title = "Sudoku solver";


// grid related constants
int gridSize = 9;
int pxCellSize = 30; //px


// texts

std::string quitText = "Press Q to quit";
std::string restartText = "Press R to restart";
int pxTextSize = 25;

sf::Font font;