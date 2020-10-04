#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include <string>


class textHandler{

	private:

		std::vector <sf::Text> texts;

	public:

		textHandler();
		void setText(const std::string &String, const sf::Vector2f &pos);
		void draw(sf::RenderWindow &window) const;
		~textHandler();

};