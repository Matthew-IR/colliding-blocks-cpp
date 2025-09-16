#include "block.hpp"

Block::Block(sf::Vector2f size, sf::Vector2f position, sf::Color fill_colour) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(fill_colour);
}


void Block::draw(sf::RenderWindow& window) {
    window.draw(shape);
}