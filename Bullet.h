#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Constants.h"
#include <iostream>

class Bullet {
private:
	bool _fly;
	coordinate::Coordinate _C;
	/*
		quarter directions - задает:
		в какую четверть смотрит вектор скорости
	*/
	char _qDirections;
	/*
		Ќаправление вектора скорости пули
	*/
	double _direction;
	/*
		ћодуль вектора скорости пули
	*/
	double _speed;

	sf::Image _I;
	sf::Texture _T;
	sf::Sprite _S;
protected:
public:
	Bullet();
	~Bullet();

	void loadImage(const char*);

	const bool getFly() const;
	void setFly(bool);

	void setCoordinate(coordinate::Coordinate&);
	const coordinate::Coordinate& getCoordinate() const;

	/*
		”становить направление полета
		пули
	*/
	void setDirection(double);
	/*
		Ётот метод реализует движение пули
	*/
	void motion(sf::Clock);

	const sf::Sprite& getSprite() const;
	friend bool operator==(const Bullet&, const Bullet&);
};

#endif BULLET_H
