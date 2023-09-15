#pragma once
#include "Entity.h"

class Player : public Entity {
public:
    Player(float x, float y, float radius, sf::Color color, float speed);
    void handleInput(float windowWidth, float windowHeight);

private:
    float speed;
};
