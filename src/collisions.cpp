#include "block.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void collisions(Block& block1, Block& block2) {

    sf::FloatRect bounds1 = block1.getGlobalBounds();
    sf::FloatRect bounds2 = block2.getGlobalBounds();
    
    if (bounds1.findIntersection(bounds2)) {
        float m1 = block1.getMass();
        float m2 = block2.getMass();

        if (m1 + m2 == 0.0f) {
            return;
        }

        sf::Vector2f u1 = block1.getVelocity();
        sf::Vector2f u2 = block2.getVelocity();

        // elastic coefficient
        float e = 1.0f;

        sf::Vector2f v1 = (m1 * u1 + m2 * u2 - m2 * e * (u1 - u2)) / (m1 + m2);
        sf::Vector2f v2 = (m1 * u1 + m2 * u2 + m1 * e * (u1 - u2)) / (m1 + m2);

        block1.setVelocity(v1);
        block2.setVelocity(v2);
    }

}