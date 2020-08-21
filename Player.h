#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Bullet.h"
#include "Constants.h"
#include "Tank.h"

/*
    Класс, который представляет танк главного игрока
*/

class Player : public Tank {
private:
    bool _shoot;
protected:
public:
    Player(const char*, int, double);
    ~Player();

    void setShoot(bool);
    bool getShoot() const;
    /*
    Функции, связанные с членом данных health, определены
    в Player из-за reduce_health() - у каждого персонажа
    своё максимальное здоровье
    */
    int get_health() const;
    void reduce_health(int);        
    void increase_health(int);  
    /*
        Выполняет проверку координат
        на допустимость значений
    */
    bool checkCoordinates();
};

#endif