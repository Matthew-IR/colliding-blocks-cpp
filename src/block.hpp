#pragma once
#include <SFML/Graphics.hpp>

class Block {
    public:
        Block(sf::Vector2f size, sf::Vector2f position, sf::Color fill_colour);

        void update();

        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape shape;

};