#include "block.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void collisions(Block& block1, Block& block2) {

    sf::FloatRect bounds1 = block1.getGlobalBounds();
    sf::FloatRect bounds2 = block2.getGlobalBounds();
    
    if (bounds1.findIntersection(bounds2)) {
        sf::Vector2f v1 = block1.getVelocity();
        sf::Vector2f v2 = block2.getVelocity();

        block1.setVelocity(v2);
        block2.setVelocity(v1);
    }

}