#include "game.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include "cell.hpp"
#include <iostream>



game::game() : window(sf::VideoMode(width, height), Title){}



game::~game() {}



void game::run(){

    while (window.isOpen()){

        handleEvents();

        window.clear(white);
        drawGrid();
        window.display();
    }
}



void game::handleEvents(){

    sf::Event ev;

    while (window.pollEvent(ev)){

        if (ev.type == sf::Event::Closed)
            window.close();
        else if(ev.type == sf::Event::KeyPressed){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                std::cout << "R\n";
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){

                std::cout << "Q\n";
            }
        }
    }
}



void game::drawGrid(){

    for (int row = 0; row < gridSize; ++row)
        for (int col = 0; col < gridSize; ++col){

            cell Cell = cell(row, col, grid[row][col]);
            Cell.draw(window);
        }
}