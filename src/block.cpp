#include "block.hpp"

Block::Block(sf::Vector2f size, sf::Vector2f position, sf::Vector2f init_velocity, float input_mass, sf::Color fill_colour) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(fill_colour);
    velocity = init_velocity;
    mass = input_mass;
}


void Block::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Block::update(float dt) {
    shape.move(velocity * dt);
}

void Block::setVelocity(sf::Vector2f new_velocity) {
    velocity = new_velocity;
}

void Block::move(const sf::Vector2f& offset) {
    shape.move(offset);
}