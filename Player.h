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
    int _points;
    bool _shoot;
protected:
public:
    Player(const char*, int, double);
    ~Player();

    void setShoot(bool);
    bool getShoot() const;

    void changePoints(int);
    /*
        Функции, связанные с членом данных health
    */
    int get_health() const;
    void changeHealth(int);
    /*
        Выполняет проверку координат
        на допустимость значений
    */
    bool checkCoordinates();
};

#endif