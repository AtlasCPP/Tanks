#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Bullet.h"
#include "Constants.h"
#include "Tank.h"

/*
    �����, ������� ������������ ���� �������� ������
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
        �������, ��������� � ������ ������ health
    */
    int get_health() const;
    void changeHealth(int);
    /*
        ��������� �������� ���������
        �� ������������ ��������
    */
    bool checkCoordinates();
};

#endif