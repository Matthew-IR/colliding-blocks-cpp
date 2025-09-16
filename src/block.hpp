#pragma once
#include <SFML/Graphics.hpp>

class Block {
    public:
        Block(float w, float h, sf::Color fill_colour);

        void update();

        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape shape;

};