#include <string>
#include "SFML/Graphics.hpp"

// window related constants
int width = 600;
int height = 600;
std::string Title = "Sudoku solver";


// grid related constants
int gridSize = 9;
int pxCellSize = 45; //px


// texts

std::string quitText = "Press Q to quit";
std::string restartText = "Press R to restart";
int pxTextSize = 20;

sf::Font font;

int numbersCount = 10;

std::string showsolutionText = "Press S to show a solution";