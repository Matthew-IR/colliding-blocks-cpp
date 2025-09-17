#pragma once
#include <SFML/Graphics.hpp>

class Block {
    public:
        Block(sf::Vector2f size, sf::Vector2f position, sf::Vector2f init_velocity, float input_mass, sf::Color fill_colour);

        void update(float dt);

        void draw(sf::RenderWindow& window);

        void move(const sf::Vector2f& offset);

        sf::Vector2f getPosition() const {
            return shape.getPosition();
        }

        sf::Vector2f getSize() const {
            return shape.getSize();
        }

        sf::Vector2f const getVelocity() {
            return velocity;
        }

        float const getMass() {
            return mass;
        }

        void setVelocity(sf::Vector2f new_velocity);

        sf::FloatRect getGlobalBounds() {
            return shape.getGlobalBounds();
        }

    private:
        sf::RectangleShape shape;
        sf::Vector2f velocity;
        float mass;

};