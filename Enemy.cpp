#include "Enemy.h"

Enemy::Enemy() :
                   Tank(constants::ENEMY_FILE, constants::ENEMY_HEALTH, constants::ENEMY_SPEED)
{
}

Enemy::~Enemy() {
    
}

int Enemy::get_health() const {
    return health;
}

void Enemy::reduce_health(int value) {
    health -= value;
    if (health < 0)
    {
        health = 0;
    }
}

void Enemy::increase_health(int value) {
    health += value;
    if (health > constants::ENEMY_HEALTH)
    {
        health = constants::ENEMY_HEALTH;
    }
}
