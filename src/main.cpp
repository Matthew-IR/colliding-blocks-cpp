#include <SFML/Graphics.hpp>
#include "block.hpp"

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

        sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Colliding Blocks");

        Block block(10.0f, 10.0f, sf::Color::Red);

        while (window.isOpen()) {
            if (const auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }

            window.clear();

            block.draw(window);

            window.display();
        }

    return 0;
}