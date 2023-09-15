#include "Player.h"

Player::Player(float x, float y, float radius, sf::Color color, float speed)
    : Entity(x, y, radius, color), speed(speed) {}

void Player::handleInput(float windowWidth, float windowHeight) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y += speed;
    }
    checkBoundaries(windowWidth, windowHeight);
    circle.setPosition(x, y);
}
