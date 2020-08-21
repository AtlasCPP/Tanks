#include "Bullet.h"

Bullet::Bullet():
                   _speed(constants::SPEED_BULLET),
				   _direction(0),
                   _qDirections('0'),
                   _C(0, 0),
                   _fly(true)
{

}

Bullet::~Bullet() {

}

const bool Bullet::getFly() const{
    return _fly;
}

void Bullet::setFly(bool value) {
    _fly = value;
}

void Bullet::loadImage(const char *name_image) {
	_I.loadFromFile(name_image);
    _I.createMaskFromColor(sf::Color(72, 72, 69));
	_T.loadFromImage(_I);
	_S.setTexture(_T);
    _S.setTextureRect(sf::IntRect(900, 500, 2, 2));
}

void Bullet::setCoordinate(coordinate::Coordinate& Coor) {
	_C.x = Coor.x;
    _C.y = Coor.y;
    _S.move(_C.x, _C.y);
}

const coordinate::Coordinate& Bullet::getCoordinate() const{
	return _C;
}

void Bullet::setDirection(double dir) {
	_direction = dir;

    if (
        (_direction >= 0.0)
        &&
        (_direction < (constants::PI_HALF))
        )
    {
        _qDirections = '1';
    }
    else if (
        (_direction < constants::pi)
        &&
        (_direction >= (constants::PI_HALF))
        )
    {
        _qDirections = '4';
    }
    else if (
        (_direction >= constants::pi)
        &&
        (_direction < (constants::PI_HALF * 3.0))
        )
    {
        _qDirections = '3';
    }
    else if (
        (_direction >= (constants::PI_HALF * 3.0))
        &&
        (_direction < (constants::DOUBLE_PI))
        )
    {
        _qDirections = '2';
    }

}

void Bullet::motion(sf::Clock clock) {
	double dx = 0, dy = 0, vx = 0, vy = 0;
    double time = clock.getElapsedTime().asMicroseconds();
    time /= 2000;
    switch (_qDirections)
    {
    case '1':
        /*
            Двигаемся в I четверти
            dy < 0 && dx >= 0
        */
        vy -= _speed * cos(_direction);
        vx += _speed * sin(_direction);
        break;
    case '2':
        /*
            Двигаемся в II четверти
            dy <= 0 && dx < 0
        */
        vy -= _speed * cos(constants::DOUBLE_PI - _direction);
        vx -= _speed * sin(constants::DOUBLE_PI - _direction);
        break;
    case '3':
        /*
            Двигаемся в III четверти
            dy > 0 && dx <= 0
        */
        vy += _speed * sin(constants::PI_HALF * 3.0 - _direction);
        vx -= _speed * cos(constants::PI_HALF * 3.0 - _direction);
        break;
    case '4':
        /*
            Двигаемся в IV четверти
            dy >= 0 && dx > 0
        */
        vy += _speed * cos(constants::pi - _direction);
        vx += _speed * sin(constants::pi - _direction);
        break;
    }
    dx = vx * time;
    dy = vy * time;
    _C.x += dx;
    _C.y += dy;
    _S.move(dx, dy);
}

const sf::Sprite& Bullet::getSprite() const {
    return _S;
}

bool operator==(const Bullet& B1, const Bullet& B2) {
    if
    (
        (B1._C == B2._C)
        &&
        (B1._direction == B2._direction)
        &&
        (B1._qDirections == B2._qDirections)
    )
    {
        return true;
    }
    else {
        return false;
    }
}