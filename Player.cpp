#include "Player.h"

Player::Player(const char* name_image, int h, double s) : 
                   Tank(name_image, h, s),
                   _shoot(false)
{
}

Player::~Player() {

}

int Player::get_health() const {
    return health;
}

void Player::reduce_health(int value) {
    health -= value;
    if (health < 0) 
    {
        health = 0;
    }
}

void Player::increase_health(int value) {
    health += value;
    if (health > constants::PLAYERS_HEALTH) 
    {
        health = constants::PLAYERS_HEALTH;
    }
}

void Player::setShoot(bool value) {
    _shoot = value;
}

bool Player::getShoot() const{
    return _shoot;
}

bool Player::checkCoordinates() {
    coordinate::Coordinate C = this->getCoordinate();
    if (
        C.x+_dx+(constants::TANK_WIDTH/2) 
        < static_cast<double>(
            (
                constants::CARD_BLOCK_SIDE_SIZE 
                * constants::MAP_WIDTH
                - constants::CARD_BLOCK_SIDE_SIZE
            )
        )
        &&
        C.y+_dy+(constants::TANK_HEIGHT/2)
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