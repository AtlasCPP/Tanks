#include "Enemy.h"

Enemy::Enemy() :
                   Tank(constants::ENEMY_FILE, constants::ENEMY_HEALTH, constants::ENEMY_SPEED),
                   _activated(false), _allowCommit(false)
{
}

Enemy::~Enemy() {
    
}

void Enemy::toFollow(coordinate::Coordinate& Coor, sf::Clock& clock) {
    double time = clock.getElapsedTime().asMicroseconds();
    time /= 5000;
    double X = Coor.x;
    double Y = Coor.y;
    double direction = 0;
    double tmpX = Coor.x;
    double tmpY = Coor.y;
    coordinate::Coordinate currC = this->getCoordinate();
    double moduleS = sqrt((tmpX - currC.x)*(tmpX - currC.x) +
                     (tmpY - currC.y)* (tmpY - currC.y));
    if (moduleS > 2) {
        Coor.x = time * (tmpX - currC.x) / moduleS;
        Coor.y = time * (tmpY - currC.y) / moduleS;
        this->setDeltaCoordinate(Coor);
    }
    direction = atan2(Coor.y, Coor.x) + constants::PI_HALF;
    this->setRotationSprite(direction * 180.0 / constants::pi);
    std::cout << "direction enemy: " << direction * 180.0 / constants::pi << "\n";
    this->setDirection(direction * 180.0 / constants::pi);
    Coor.x = X;
    Coor.y = Y;
}

bool Enemy::getAllowCommit() {
    return _allowCommit;
}

void Enemy::setAllowCommit(bool value) {
    _allowCommit = value;
}

bool Enemy::getActivated() {
    return _activated;
}

void Enemy::setActivated(bool value) {
    _activated = value;
}

int Enemy::get_health() const {
    return health;
}

void Enemy::changeHealth(int value) {
    if (health + value < 0) {
        health = 0;
    }
    else if (health + value > constants::MAX_PLAYERS_HEALTH) {
        health = constants::MAX_PLAYERS_HEALTH;
    }
    else {
        health += value;
    }
}

bool Enemy::checkCoordinates() {
    coordinate::Coordinate C = this->getCoordinate();
    if (
        C.x + _dx + (constants::TANK_WIDTH / 2)
        < static_cast<double>(
            (
                constants::CARD_BLOCK_SIDE_SIZE
                * constants::MAP_WIDTH
                - constants::CARD_BLOCK_SIDE_SIZE
                )
            )
        &&
        C.y + _dy + (constants::TANK_HEIGHT / 2)
        < static_cast<double>(
            (
                constants::CARD_BLOCK_SIDE_SIZE
                * constants::MAP_HEIGHT
                - (constants::CARD_BLOCK_SIDE_SIZE / 2)
                )
            )
        &&
        C.x + _dx - (constants::TANK_WIDTH / 2) > 0
        &&
        C.y + _dy - (constants::TANK_HEIGHT / 2) > 0
        )
    {
        return true;
    }
    return false;
}