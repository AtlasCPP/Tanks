#include "Tank.h"

Tank::Tank(const char* name_file, int h, double s) :
                   _speed(s),
                   _curr_dev_y(0),
                   _direction(0),
                   health(h),
                   _C(100.1, 100.1),
                   _size_Stor(0),
                   _dx(0),_dy(0)
{
    _I.loadFromFile(name_file);
    _I.createMaskFromColor(sf::Color(0, 0, 0));
    _T.loadFromImage(_I);
    _S.setTexture(_T);
    _S.setOrigin(36, 73);
    _S.setPosition(100.1, 100.1);
}

Tank::~Tank() {

}

coordinate::Coordinate& Tank::getCoordinate() {
    return _C;
}

void Tank::setCoordinate(coordinate::Coordinate& Coor) {
    _C.x = Coor.x;
    _C.y = Coor.y;
    _S.setPosition(_C.x, _C.y);
}

const sf::Sprite& Tank::getSprite() const {
    return _S;
}

double Tank::getDirection() const {
    return _direction;
}

void Tank::rotation(double rotation_value, sf::Clock& clock) {
    double time = clock.getElapsedTime().asMicroseconds();
    time /= 5000;
    _curr_dev_y += (rotation_value * time);
    if (_curr_dev_y >= 0) 
    {
        _direction = ((abs(_curr_dev_y) / (constants::DOUBLE_PI))
            - static_cast<int>(abs(_curr_dev_y) / (constants::DOUBLE_PI)))
            * constants::pi * 2.0;
    }
    else 
    {
        _direction = (constants::DOUBLE_PI)
            - ((abs(_curr_dev_y) / (constants::DOUBLE_PI))
            - static_cast<int>(abs(_curr_dev_y) / (constants::DOUBLE_PI)))
            * constants::pi * 2.0;
    }
    _S.setRotation(_curr_dev_y / constants::pi * 180.0);
}

void Tank::motion(bool forward, sf::Clock& clock) {
    double time = clock.getElapsedTime().asMicroseconds();
    time /= 5000;
    _speed = (forward == true) ? _speed : -_speed;
    double vx = 0;
    double vy = 0;
    if  (
        (_direction >= 0.0) 
        &&
        (_direction < (constants::PI_HALF))
        ) 
    {
        /*
            Двигаемся в I четверти
            dy < 0 && dx >= 0
        */
        vy -= _speed * cos(_direction);
        vx += _speed * sin(_direction);
    }
    else if (
            (_direction < constants::pi)
            &&
            (_direction >= (constants::PI_HALF))
            )
    {
        /*
            Двигаемся в IV четверти
            dy >= 0 && dx > 0
        */
        vy += _speed * cos(constants::pi - _direction);
        vx += _speed * sin(constants::pi - _direction);
    }
    else if (
            (_direction >= constants::pi)
            &&
            (_direction < (constants::pi / 2.0 * 3.0))
            )
    {
        /*
            Двигаемся в III четверти
            dy > 0 && dx <= 0
        */
        vy += _speed * sin(constants::pi / 2.0 * 3.0 - _direction);
        vx -= _speed * cos(constants::pi / 2.0 * 3.0 - _direction);
    }
    else if (
            (_direction >= (constants::pi / 2.0 * 3.0))
            &&
            (_direction < (constants::DOUBLE_PI))
            )
    {
        /*
            Двигаемся в II четверти
            dy <= 0 && dx < 0
        */
        vy -= _speed * cos(constants::DOUBLE_PI - _direction);
        vx -= _speed * sin(constants::DOUBLE_PI - _direction);
    }
    _dx = vx * time;
    _dy = vy * time;
    _speed = (forward == true) ? _speed : -_speed;
}

void Tank::shoot() {
    /*
        Помещаем новый объект в список
    */
    if (_size_Stor >= constants::MAXIMUM_BULLETS) {
        std::cout << "STORE IS FULL\n";
        return;
    }
    else {
        _Storage_Bullet.resize(_size_Stor+1);
        std::list<Bullet>::iterator iter = _Storage_Bullet.end();
        --iter;
        iter->loadImage(constants::BULLET_FILE);
        iter->setCoordinate(_C);
        iter->setDirection(_direction);
        ++_size_Stor;
    }
}

void Tank::drawBullets(Window& window) const{
    std::list<Bullet>::const_iterator iter = _Storage_Bullet.begin();
    std::list<Bullet>::const_iterator eiter = _Storage_Bullet.end();
    while (iter != eiter) {
        window.draw(iter->getSprite());
        ++iter;
    }
}

std::list<Bullet>& Tank::getStorageBullet() {
    return _Storage_Bullet;
}

bool Tank::searchInField(const coordinate::Coordinate& Coor) {
    if ((Coor.x >= _C.x - 20.0) && (Coor.x <= _C.x + 20.0) &&
        (Coor.y >= _C.y - 20.0) && (Coor.y <= _C.y + 20.0)) {
        return true;
    } 
    return false;
}

void Tank::BulletFlightHandler(sf::Clock& clock) {
    std::list<Bullet>::iterator iter = _Storage_Bullet.begin();
    while (iter != _Storage_Bullet.end()) {
        if (
            (
                iter->getCoordinate().x
                <= (constants::CARD_BLOCK_SIDE_SIZE * constants::MAP_WIDTH)
                )
            &&
            (
                iter->getCoordinate().y
                <= (constants::CARD_BLOCK_SIDE_SIZE * constants::MAP_HEIGHT)
                )
            &&
            (
                iter->getCoordinate().x
                >= 0
                )
            &&
            (
                iter->getCoordinate().y
                >= 0
                )
            && iter->getFly()
            )
        {
            iter->motion(clock);
            ++iter;
        }
        else {
            --_size_Stor;
            iter->setFly(false);
            iter = _Storage_Bullet.erase(iter);
        }
    }
}

void Tank::commitChanges() {
    /*
        Двигаем танк
    */
    _C.x += _dx;
    _C.y += _dy;
    _S.move(_dx, _dy);
    discardChanges();
}

void Tank::discardChanges() {
    _dx = 0.0;
    _dy = 0.0;
}