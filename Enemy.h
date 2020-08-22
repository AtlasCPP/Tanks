#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Tank.h"

/*
	Класс, который представляет танк врага
*/

class Enemy : public Tank {
private:
	bool _allowCommit;
	bool _activated;
protected:
public:
	Enemy();
	~Enemy();

	void toFollow(coordinate::Coordinate&, sf::Clock&);

	bool getAllowCommit();
	void setAllowCommit(bool);

	bool getActivated();
	void setActivated(bool);
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
