#pragma once
#include "Entity.h"
#include <cstdlib>
#include <ctime>

class Monster : public Entity {
public:
    Monster(float x, float y, float radius, sf::Color color, float speed);
    void wander(float windowWidth, float windowHeight);
    void chase(const Entity& target);

private:
    float speed;
    float dx, dy;
    int counter;
    float radius;
};
