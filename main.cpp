#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "=== Advanced Circle Customizer ===" << std::endl;
    
    // Get circle size
    float radius;
    std::cout << "Enter circle radius (e.g., 100): ";
    std::cin >> radius;
    
    // Get point count (shape type)
    int pointChoice;
    std::cout << "\nChoose shape:" << std::endl;
    std::cout << "1. Triangle (3 points)" << std::endl;
    std::cout << "2. Square (4 points)" << std::endl;
    std::cout << "3. Pentagon (5 points)" << std::endl;
    std::cout << "4. Octagon (8 points)" << std::endl;
    std::cout << "5. Circle (full circle)" << std::endl;
    std::cout << "Enter choice (1-5): ";
    std::cin >> pointChoice;
    
    int pointCount = 30; // Default for circle
    switch(pointChoice) {
        case 1: pointCount = 3; break;
        case 2: pointCount = 4; break;
        case 3: pointCount = 5; break;
        case 4: pointCount = 8; break;
        case 5: pointCount = 30; break;
        default: 
            std::cout << "Invalid choice, defaulting to Circle" << std::endl;
            pointCount = 30;
    }
    
    // Get RGB color values
    int r, g, b;
    std::cout << "\nCustomize color (RGB values 0-255):" << std::endl;
    std::cout << "Enter Red value (0-255): ";
    std::cin >> r;
    std::cout << "Enter Green value (0-255): ";
    std::cin >> g;
    std::cout << "Enter Blue value (0-255): ";
    std::cin >> b;
    
    // Clamp values to valid range
    r = (r < 0) ? 0 : (r > 255) ? 255 : r;
    g = (g < 0) ? 0 : (g > 255) ? 255 : g;
    b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    
    std::cout << "Color set to RGB(" << r << ", " << g << ", " << b << ")" << std::endl;
    
    // Get position
    float posX, posY;
    std::cout << "\nEnter X position (0-800): ";
    std::cin >> posX;
    std::cout << "Enter Y position (0-600): ";
    std::cin >> posY;
    
    // Create window
    std::cout << "\nCreating window..." << std::endl;
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Advanced Interactive Circle", sf::State::Windowed, settings);
    
    // Create shape with user settings
    sf::CircleShape shape(radius, pointCount);
    shape.setFillColor(sf::Color(r, g, b));
    shape.setPosition({posX, posY});
    
    std::cout << "Window created! Close the window to exit." << std::endl;
    std::cout << "\nYour shape:" << std::endl;
    std::cout << "  - Radius: " << radius << std::endl;
    std::cout << "  - Points: " << pointCount << std::endl;
    std::cout << "  - Color: RGB(" << r << ", " << g << ", " << b << ")" << std::endl;
    std::cout << "  - Position: (" << posX << ", " << posY << ")" << std::endl;
    
    // Main loop
    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(shape);
        window.display();
    }
    
    std::cout << "Program ended." << std::endl;
    return 0;
}