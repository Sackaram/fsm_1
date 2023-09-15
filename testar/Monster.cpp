#include "Monster.h"
#include <iostream>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

Monster::Monster(float x, float y, float radius, sf::Color color, float speed)
    : Entity(x, y, radius, color), radius(radius),  speed(speed), counter(4000) {
    dx = ((float)rand() / RAND_MAX - 0.5f) * 0.012f;
    dy = ((float)rand() / RAND_MAX - 0.5f) * 0.012f;
}

void Monster::wander(float windowWidth, float windowHeight) {
    static sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    circle.setFillColor(sf::Color::Yellow);  // Setting the color to yellow

    if (elapsed.asSeconds() >= 1.5f) {
        dx = ((float)rand() / RAND_MAX - 0.5f) * speed;  // Randomizing direction
        dy = ((float)rand() / RAND_MAX - 0.5f) * speed;

        


        speed *= 1.25f;  // Increasing speed by 25%
        clock.restart();  // Reset the clock
    }
    std::cout << "Before: x = " << x << std::endl;
    x += dx;
    std::cout << "After: x = " << x << std::endl;
    std::cout << "dx = " << dx << std::endl;
    // Updating position
    //x += dx;
    y += dy;

    // Boundary check and updating position
    checkBoundaries(windowWidth, windowHeight);
    circle.setPosition(x, y);
}






void Monster::chase(const Entity& target) {
    speed = 0.015f;
    circle.setFillColor(sf::Color::Red);
    float dx = target.getX() - x;
    float dy = target.getY() - y;
    float mag = std::sqrt(dx * dx + dy * dy);

    if (mag > 0.0f) {
        dx /= mag;
        dy /= mag;
        x += dx * speed;
        y += dy * speed;
    }

    circle.setPosition(x, y);
}
