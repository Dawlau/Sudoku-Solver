#include "eventHandler.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "game.hpp"
#include "Generator.hpp"


eventHandler::eventHandler(){}


eventHandler::eventHandler(sf::RenderWindow *window, NumberBar *bar, Grid *grid, int *selectedNumber) : window(window), bar(bar), grid(grid), selectedNumber(selectedNumber){

    violation = false;
    redCell = {-1, -1};
}



void eventHandler::handle() const{

	sf::Event ev;

    while ((*window).pollEvent(ev)){

        if (ev.type == sf::Event::Closed)
            (*window).close();
        else if (ev.type == sf::Event::KeyPressed)
            handleKeyboard();
        else if(ev.type == sf::Event::MouseButtonPressed){

            sf::Vector2i clickCoords = sf::Mouse::getPosition(*window);
            handleMouse(clickCoords);
        }
    }
}




void eventHandler::handleKeyboard() const{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        restartGame();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        (*window).close();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        Solver::solve(*grid, *window);
}



void eventHandler::handleMouse(sf::Vector2i &clickCoords) const{

	std::pair <int, int> Cell = (*grid).checkClick(clickCoords);
    if(Cell.first != -1){ // clicked in grid

        int row = Cell.first;
        int col = Cell.second;

        if((*grid).getCellGenerated(row, col))
            return ;

        bool checkAdd = (    (*grid).getNumber(row, col) == 0 and !violation    );
        bool checkDelete = (   (*selectedNumber) == 0 and !(*grid).getCellGenerated(row, col)   );

		if (    checkAdd  or checkDelete ){
        	(*grid).setNumber(row, col, (*selectedNumber));
            violation = checkViolation(*grid);
        }

        if(violation){
            (*grid).setCellTextColor(row, col, sf::Color::Red);

            if(redCell.first == -1)
                redCell = {row, col};
        }
        else {

            if(redCell.first != -1)
                (*grid).setCellTextColor(redCell.first, redCell.second, sf::Color::Blue);
            redCell = {-1, -1};
        }

        return;
    }

    int idx = (*bar).checkClick(clickCoords);
    if(idx != -1){ // clicked on a number

        (*bar).changeOutlineColor((*selectedNumber), sf::Color::Black);
        (*selectedNumber) = idx;
        (*bar).changeOutlineColor((*selectedNumber), sf::Color::Green);

        return;
    }
}



void eventHandler::restartGame() const{

    *grid = Grid();
    *bar = NumberBar();
    *selectedNumber = 0;
    violation = false;

    Generator::generate(*grid);
}



bool eventHandler::checkViolation(Grid &grid){
    return checkRowViolation(grid) or checkColViolation(grid) or checkSquareViolation(grid);
}



bool eventHandler::checkRowViolation(Grid &grid){

    std::vector < std::vector <int> > freq(gridSize, std::vector <int> (numbersCount));

    for(int row = 0; row < gridSize; ++row){

        for(int col = 0; col < gridSize; ++col)
            ++freq[row][grid.getNumber(row, col)];

        for(int no = 1; no < numbersCount; ++no)
            if(freq[row][no] > 1)
                return true;
    }
    return false;
}



bool eventHandler::checkColViolation(Grid &grid){

    std::vector < std::vector <int> > freq(gridSize, std::vector <int> (numbersCount));

    for(int col = 0; col < gridSize; ++col){

        for(int row = 0; row < gridSize; ++row)
            ++freq[col][grid.getNumber(row, col)];

        for(int no = 1; no < numbersCount; ++no)
            if(freq[col][no] > 1)
                return true;
    }

    return false;
}


bool eventHandler::checkSquareViolation(Grid &grid){

    for(int R = 0; R < gridSize; R += 3)
        for(int C = 0; C < gridSize; C += 3){

            std::vector <int> freq(numbersCount);

            for(int row = R; row < R + 3; ++row)
                for(int col = C; col < C + 3; ++col)
                    ++freq[grid.getNumber(row, col)];

            for(int no = 1; no < numbersCount; ++no)
                if(freq[no] > 1)
                    return true;
        }

    return false;
}



bool eventHandler::checkEnd(Grid &grid){

    int cnt0 = 0;
    for(int row = 0; row < gridSize; ++row)
        for(int col = 0; col < gridSize; ++col)
            if(grid.getNumber(row, col) == 0)
                ++cnt0;

    return (cnt0 == 0);
}



eventHandler::~eventHandler(){}