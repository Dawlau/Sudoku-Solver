#include "Rectangle.hpp"
#include "SFML/Graphics.hpp"


Rectangle::Rectangle(const sf::RectangleShape &rect) {
	this->rect = rect;
}

Rectangle::~Rectangle(){

}

bool Rectangle::isClicked(const sf::Vector2i &clickCoords) const{

	int x = clickCoords.x;
	int y = clickCoords.y;

	double topx = rect.getPosition().x;
	double topy = rect.getPosition().y;

	int rectWidth = rect.getGlobalBounds().width;
	int rectHeight = rect.getGlobalBounds().height;

	double botx = topx + rectWidth;
	double boty = topy + rectHeight;

	return (topx < x and x < botx and topy < y and y < boty);
}


sf::RectangleShape Rectangle::getRect() const{
	return rect;
}


void Rectangle::drawInto(sf::RenderWindow &window){
	window.draw(rect);
}


void Rectangle::setRect(sf::RectangleShape &rect){
	this->rect = rect;
}


Rectangle& Rectangle::operator =(const Rectangle &other){
	rect = other.rect;
	return *this;
}
