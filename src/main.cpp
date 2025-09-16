#include <SFML/Graphics.hpp>

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

        sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Colliding Blocks");

        while (window.isOpen()) {
            if (const auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }

            window.clear();
            window.display();
        }

    return 0;
}