#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Window.h"
#include "Constants.h"
#include "Bullet.h"
#include "Coordinate.h"

/*
    Класс, который представляет любой танк
    (этот класс абстрактный)
*/

class Tank {
private:
    int _size_Stor;
    std::list<Bullet> _Storage_Bullet;
    coordinate::Coordinate _C;
    double _speed;
    /*
        Current deviation from the y-axis
        (текущее отклонение от оси y,
        ось y расположена в 0рад от вертикали)
        угол задается в радианах + 
        направление вектора скорости
    */
    double _curr_dev_y;
    /*
        Текущее направление игрока
        (или вектора скорости) - 
        не может быть больше 2pi
    */
    double _direction;
    sf::Image _I;
    sf::Texture _T;
    sf::Sprite _S;
protected:
    /*
        В конструкторе загружаем картинку, затем картинку
        загружаем в текстуру, а текстуру загружаем в спрайт
    */
    double _dx;
    double _dy;
    int health;
    Tank(const char*, int, double);
    ~Tank();
public:
    /*
        Поворот на угол
        (угол задается в радианах)
    */
    void rotation(double, sf::Clock&);
    /*
        Движение по прямой в текущем положении
        (аргумент может быть отрицательным - 
        движение в обратном направлении)
    */
    void motion(bool, sf::Clock&);
    /*
        Осуществляет возможность стрелять
    */
    void shoot();
    void drawBullets(Window&) const;
    std::list<Bullet>& getStorageBullet();

    const sf::Sprite& getSprite() const;
    coordinate::Coordinate& getCoordinate();
    void setCoordinate(coordinate::Coordinate&);
    double getDirection() const;

    bool searchInField(const coordinate::Coordinate&);

    void BulletFlightHandler(sf::Clock& clock);

    virtual int get_health() const = 0;
    virtual void reduce_health(int) = 0;
    virtual void increase_health(int) = 0;
    /*
        Закрепляет все запросы на 
        изменение значения полей
        танка
    */
    void commitChanges();
    /*
        Сбрасывает запрашиваемые изменения
    */
    void discardChanges();
};

#endif