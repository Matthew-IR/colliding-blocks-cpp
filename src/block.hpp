#pragma once
#include <SFML/Graphics.hpp>

class Block {
    public:
        Block(sf::Vector2f size, sf::Vector2f position, sf::Vector2f init_velocity, sf::Color fill_colour);

        void update(float dt);

        void draw(sf::RenderWindow& window);

        sf::Vector2f getPosition() const {
            return shape.getPosition();
        }

        sf::Vector2f getSize() const {
            return shape.getSize();
        }

        void setVelocity(sf::Vector2f new_velocity);

    private:
        sf::RectangleShape shape;
        sf::Vector2f velocity;

};