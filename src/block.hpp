#pragma once
#include <SFML/Graphics.hpp>

class Block {
    public:
        Block(sf::Vector2f size, sf::Vector2f position, sf::Color fill_colour);

        void update();

        void draw(sf::RenderWindow& window);

        sf::Vector2f getPosition() const {
            return shape.getPosition();
        }

        sf::Vector2f getSize() const {
            return shape.getSize();
        }

    private:
        sf::RectangleShape shape;

};