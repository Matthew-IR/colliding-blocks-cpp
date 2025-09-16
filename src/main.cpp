#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "collisions.hpp"

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

        sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Colliding Blocks");

        sf::Vector2f block1_size = {10.0f, 10.0f};
        sf::Vector2f block1_position = {300.0f, 0.0f};
        sf::Vector2f block1_init_velocity = {100.0f, 0.0f};
        sf::Vector2f block2_size = {10.0f, 10.0f};
        sf::Vector2f block2_position = {600.0f, 0.0f};
        sf::Vector2f block2_init_velocity = {-100.0f, 0.0f};
        
        Block block1(block1_size, block1_position, block1_init_velocity, sf::Color::Red);
        Block block2(block2_size, block2_position, block2_init_velocity, sf::Color::Green);

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

            window.clear();

            block1.draw(window);
            block2.draw(window);

            window.display();
        }

    return 0;
}