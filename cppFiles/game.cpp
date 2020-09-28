#include "game.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"


game::game() : window(sf::VideoMode(width, height), Title){

}

game::~game(){}


void game::run(){

    while(window.isOpen()){

        handleEvents();

        window.clear(white);
        window.display();
    }
}


void game::handleEvents(){

    sf::Event ev;

    while(window.pollEvent(ev)){

        if(ev.type == sf::Event::Closed)
            window.close();

    }
}