#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Monster.h"

void drawLine(sf::RenderWindow& window, float x1, float y1, float x2, float y2, sf::Color color);

extern const int SCREEN_WIDTH = 1400;
extern const int SCREEN_HEIGHT = 2200;

int main() {
    std::cout << "Hello World!\n";

    sf::RenderWindow window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "My SFML Window");

    std::srand(std::time(nullptr)); // Seed for random numbers for monster movement

    Player player(1200.0f, 500.0f, 25.0f, sf::Color::Green, 0.1f);
    Monster monster(1100.0f, 700.0f, 25.0f, sf::Color::Yellow, 0.99f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput(2200, 1400);

        float dist = player.distanceTo(monster);

        window.clear(sf::Color::Black); // Clear the window

        if (dist < 400.0f) {
            monster.chase(player);
            drawLine(window,
                player.getX() + player.getRadius(), player.getY() + player.getRadius(),
                monster.getX() + monster.getRadius(), monster.getY() + monster.getRadius(),
                sf::Color::White);
        }
        else {
            monster.wander(2200, 1400);
        }

        player.render(window);
        monster.render(window);
        window.display();
    }

    return 0;
}

void drawLine(sf::RenderWindow& window, float x1, float y1, float x2, float y2, sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1), color),
        sf::Vertex(sf::Vector2f(x2, y2), color)
    };
    window.draw(line, 2, sf::Lines);
}





// Monster should stop moving towards edges