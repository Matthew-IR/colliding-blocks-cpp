#include "block.hpp"

Block::Block(float w, float h, sf::Color fill_colour) {
    shape.setSize({w,h});
    shape.setFillColor(fill_colour);
}


void Block::draw(sf::RenderWindow& window) {
    window.draw(shape);
}