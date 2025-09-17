#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "collisions.hpp"
#include "wallcollisions.hpp"

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

        sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Colliding Blocks");

        sf::Vector2f block1_size = {10.0f, 10.0f};
        sf::Vector2f block1_position = {300.0f, 0.0f};
        sf::Vector2f block1_init_velocity = {100.0f, 0.0f};
        float block1_mass = 10000.0f;
        sf::Vector2f block2_size = {10.0f, 10.0f};
        sf::Vector2f block2_position = {600.0f, 0.0f};
        sf::Vector2f block2_init_velocity = {-100.0f, 0.0f};
        float block2_mass = 100.0f;

        Block block1(block1_size, block1_position, block1_init_velocity, block1_mass, sf::Color::Red);
        Block block2(block2_size, block2_position, block2_init_velocity, block2_mass, sf::Color::Green);

        // Walls
        sf::Vector2f wall_size = {20.0f, 1000.0f};
        sf::Vector2f leftwall_position = {0.0f, 0.0f};
        sf::Vector2f rightwall_position = {WINDOW_WIDTH - 20.0f, 0.0f};
        sf::Vector2f wall_velocity = {20.0f, 0.0f};

        Block leftwall(wall_size, leftwall_position, wall_velocity, 0.0f, sf::Color::White);
        Block rightwall(wall_size, rightwall_position, wall_velocity, 0.0f, sf::Color::White);

        sf::Clock clock;

        while (window.isOpen()) {
            if (const auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }

            float dt = clock.restart().asSeconds();

            block1.update(dt);
            block2.update(dt);

            collisions(block1, block2);
            wall_collisions(block1, leftwall);
            wall_collisions(block2, rightwall);

            window.clear();

            leftwall.draw(window);
            rightwall.draw(window);

            block1.draw(window);
            block2.draw(window);

            window.display();
        }

    return 0;
}