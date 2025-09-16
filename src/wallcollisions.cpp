#include "block.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void wall_collisions(Block& block, Block& wall) {

    sf::FloatRect bounds = block.getGlobalBounds();
    sf::FloatRect wallbounds = wall.getGlobalBounds();

    if (bounds.findIntersection(wallbounds)) {
        sf::Vector2f v1 = block.getVelocity();
        v1.x *= -1;
        v1.y *= -1;

        block.setVelocity(v1);
    }
}