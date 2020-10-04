#include "game.hpp"
#include "SFML/Graphics.hpp"
#include "cell.hpp"
#include "constants.hpp"
#include <vector>
#include <iostream>



game::game() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(width, height), Title, sf::Style::Close, settings);
    evHandler = eventHandler(&window, &bar, &grid, &selectedNumber);


    evHandler.restartGame();

    if(!font.loadFromFile("fonts/Roboto-Black.ttf"))
        std::cout << "Error loading font\n";
}



void game::run(){

    while (window.isOpen()){

        evHandler.handle();

        window.clear(sf::Color::White);

        bar.draw(window);
        grid.draw(window);
        txtHandler.draw(window);

        window.display();
    }
}


game::~game() {}