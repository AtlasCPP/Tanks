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
protected:
public:
	Enemy();
	~Enemy();

	int get_health() const;
	void reduce_health(int);
	void increase_health(int);
};

#endif
