#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
	Получаем число pi -
	оно необходимо для работы
	в радианах
*/

#define _USE_MATH_DEFINES
#include <math.h>

namespace constants {

	const int WINDOW_WIDTH = 1920;			  //Ширина главного окна
	const int WINDOW_HEIGHT = 1080;			  //Высота главного окна
	const int NUMBER_OF_ENEMIES = 1;		  //Количество врагов
	const int PLAYERS_HEALTH = 100;			  //Здоровье главного игрока
	const int ENEMY_HEALTH = 40;              //Здоровье врага
	const int HEALTH_OF_THE_ENEMY = 20;		  //Здоровье врага
	const int MAP_WIDTH = 40;				  //Ширина карты
	const int MAP_HEIGHT = 25;				  //Высота карты
	const int CARD_BLOCK_SIDE_SIZE = 64;      //Блок - квадратный (px)
	const double SPEED = 1.;     			  //Модуль вектора скорости
	const double ENEMY_SPEED = 1.;            //Модуль скорости врага
	const double pi = M_PI;					  //Число пи
	const double PI_HALF = M_PI / 2.0;		  //Pi in half
	const double DOUBLE_PI = M_PI * 2.0;      //Два пи
	const double SPEED_BULLET = 1.;           //Модуль скорости пули
	const int MAXIMUM_BULLETS = 50; 		  //Максимальное количество пуль
	const double ROTATION_SPEED = 0.003; 	  //Угловая скорость(рад)
	const double TANK_WIDTH = 72.;		      //Ширина танка
	const double TANK_HEIGHT = 146.;          //Высота танка
	const char* const MAP_IMAGE = "Images/Ground.jpg";
	const char* const MAP_FILE = "map.txt";
	const char* const PLAYER_FILE = "Images/Green.bmp";
	const char* const ENEMY_FILE = "Images/Red.bmp";
	const char* const NAME_WINDOW = "Tank";
	const char* const BULLET_FILE = "Images/Bullet.bmp";

}

#endif