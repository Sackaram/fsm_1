#include "Entity.h"

Entity::Entity(float x, float y, float radius, sf::Color color)
    : x(x), y(y), radius(radius), color(color) {
    circle.setRadius(radius);
    circle.setFillColor(color);
    circle.setPosition(x, y);
}

float Entity::getX() const { return x; }
float Entity::getY() const { return y; }
float Entity::getRadius() const { return radius; }

void Entity::render(sf::RenderWindow& window) {
    window.draw(circle);
}

float Entity::distanceTo(const Entity& other) const {
    return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

void Entity::checkBoundaries(float windowWidth, float windowHeight) {
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > windowWidth - 2 * radius) x = windowWidth - 2 * radius;
    if (y > windowHeight - 2 * radius) y = windowHeight - 2 * radius;
}
