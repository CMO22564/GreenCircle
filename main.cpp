#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    // Create a file to which we can redirect output if needed
    std::ofstream file("sfml-log.txt");

    std::cout << "SFML app starting..." << std::endl;

    // Create window with context settings
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Hello SFML 3.0 Window", sf::State::Windowed, settings);
    
    std::cout << "Window created!" << std::endl;

    // Create green circle
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({350.f, 250.f});

    // Main loop
    while (window.isOpen()) {
        // Event polling
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Rendering
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}