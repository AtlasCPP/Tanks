#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Coordinate.h"
#include "Constants.h"


/*
	Класс карты
*/

class Map {
private:
	coordinate::Coordinate _currC;
	sf::Image _I;
	sf::Texture _T;
	sf::Sprite _currS;
	char _TileMap[constants::MAP_HEIGHT][constants::MAP_WIDTH];
protected:
public:
	Map();
	~Map();

	const char* getTileMap();

	sf::Sprite& get_curr_Sprite();

	void load_map_image(const char*);

	void load_map_from_file(const char*);

	void drawMap(Window&);

	/*
		Функция для проверки символа на карте.
		Возвращает true и ставит нужный спрайт
		, если в данной точке находится 
		известный символ
	*/

	bool check_point_on_the_map(const coordinate::Coordinate&);
};

#endif