#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Entity {
public:
    Entity(float x, float y, float radius, sf::Color color);
    float getX() const;
    float getY() const;
    float getRadius() const;
    void render(sf::RenderWindow& window);
    float distanceTo(const Entity& other) const;

protected:
    void checkBoundaries(float windowWidth, float windowHeight);
    float x, y;
    float radius;
    sf::Color color;
    sf::CircleShape circle;
};
