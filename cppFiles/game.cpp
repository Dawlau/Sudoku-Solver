#include "game.hpp"
#include "SFML/Graphics.hpp"
#include "cell.hpp"
#include "constants.hpp"
#include <iostream>
#include <vector>



game::game() : window(sf::VideoMode(width, height), Title) {

    restartGame();
    if(!font.loadFromFile("fonts/Roboto-Black.ttf"))
        std::cout << "Error loading font\n";
}

game::~game() {}

void game::run(){

    while (window.isOpen()){

        handleEvents();

        window.clear(sf::Color::White);

        drawGrid();
        drawControls();

        window.display();
    }
}

void game::handleEvents(){

    sf::Event ev;

    while (window.pollEvent(ev))
    {

        if (ev.type == sf::Event::Closed)
            window.close();
        else if (ev.type == sf::Event::KeyPressed)
        {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                restartGame();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
        }
    }
}


void game::drawGrid(){


    for (int row = 0; row < gridSize; ++row)
        for (int col = 0; col < gridSize; ++col){
            grid[row][col].drawInto(window);
        }

    for (int row = 0; row < gridSize; row += 3)
        for (int col = 0; col < gridSize; col += 3){

            sf::RectangleShape rect;

            rect.setSize(sf::Vector2f(3 * pxCellSize, 3 * pxCellSize));
            rect.setOutlineColor(sf::Color::Black);
            rect.setFillColor(sf::Color::Transparent);

            rect.setOutlineThickness(2);

            int pxGridSize = pxCellSize * gridSize;

            int XoffSet = width / 2 - pxGridSize / 2;
            int YoffSet = height / 2 - pxGridSize / 2;

            int x = row * pxCellSize + XoffSet;
            int y = col * pxCellSize + YoffSet;

            rect.setPosition(sf::Vector2f(x, y));

            window.draw(rect);

            rect.setOutlineThickness(-2);
            window.draw(rect);
        }
}


void game::restartGame(){

    grid = std :: vector < std :: vector <cell> > (gridSize, std::vector <cell> (gridSize));

    for (int row = 0; row < gridSize; ++row)
        for (int col = 0; col < gridSize; ++col){
            grid[row][col] = cell(row, col, 5);
        }
}


void game::drawControls(){

    sf::Text Q;
    Q.setFont(font);
    Q.setFillColor(sf::Color::Black);
    Q.setCharacterSize(pxTextSize);
    Q.setString(quitText);

    window.draw(Q);

    sf::Text R;
    R.setFont(font);
    R.setFillColor(sf::Color::Black);
    R.setCharacterSize(pxTextSize);
    R.setString(restartText);

    sf::FloatRect Qrect = Q.getGlobalBounds();
    R.setPosition(sf::Vector2f(0, Qrect.height));

    window.draw(R);
}