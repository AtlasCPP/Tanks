#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

const char* Map::getTileMap() {
	return &(_TileMap[0][0]);
}

sf::Sprite& Map::get_curr_Sprite() {
	return _currS;
}

void Map::drawMap(Window& window) {
	for (int Y = 0; Y < constants::MAP_HEIGHT; ++Y) {
		_currC.y = Y;
		for (int X = 0; X < constants::MAP_WIDTH; ++X) {
			_currC.x = X;
			if (check_point_on_the_map(_currC)) {
				window.draw(_currS);
			}
		}
	}
}

void Map::load_map_image(const char* file_image) {
	/*
		Загрузка изображений карты в поле I.
		Загрузка изображения в текстуру.
		Загрузка текстуры в спрайт.
		(Спрайт называется current, так как
		значение Rect постоянно будет меняться)
	*/
	_I.loadFromFile(file_image);
	_T.loadFromImage(_I);
	_currS.setTexture(_T);
}

void Map::load_map_from_file(const char* file_map) {
	/*
		Загрузка карты в TileMap
	*/
	std::ifstream  inf(file_map);
	if (!inf) {
		std::cerr << "File not is open!!!" << std::endl;
		exit(1);
	}
	else {
		char c;

		for (int y = 0; y < constants::MAP_HEIGHT - 1; ++y) {

			for (int x = 0; x < constants::MAP_WIDTH - 1; ++x) {

				if (inf) {
					inf >> c;
					_TileMap[y][x] = c;
				}

			}

		}

	}
	inf.close();
}

bool Map::check_point_on_the_map(const coordinate::Coordinate& Coor) {
	// флаг известного символа (famous symbol flag)
	bool fsf = false;
	
	switch ( _TileMap[static_cast<int>(Coor.y)][static_cast<int>(Coor.x)] )
	{
	case '#':
		_currS.setTextureRect(sf::IntRect(256, 170, 64, 64));
		fsf = true;
		break;
	case '7':
		_currS.setTextureRect(sf::IntRect(60, 170, 64, 64));
		fsf = true;
		break;
	case '8':
		_currS.setTextureRect(sf::IntRect(480, 170, 64, 64));
		fsf = true;
		break;
	case '5':
		_currS.setTextureRect(sf::IntRect(258, 30, 64, 64));
		fsf = true;
		break;
	case '6':
		_currS.setTextureRect(sf::IntRect(256, 328, 64, 64));
		fsf = true;
		break;
	case '3':
		_currS.setTextureRect(sf::IntRect(60, 328, 64, 64));
		fsf = true;
		break;
	case '4':
		_currS.setTextureRect(sf::IntRect(480, 328, 64, 64));
		fsf = true;
		break;
	case '1':
		_currS.setTextureRect(sf::IntRect(60, 30, 64, 64));
		fsf = true;
		break;
	case '2':
		_currS.setTextureRect(sf::IntRect(480, 30, 64, 64));
		fsf = true;
		break;
	}
	_currS.setPosition
	(
		static_cast<float>(Coor.x) 
		* static_cast<float>(constants::CARD_BLOCK_SIDE_SIZE),
		static_cast<float>(Coor.y) 
		* static_cast<float>(constants::CARD_BLOCK_SIDE_SIZE)
	);
		

	return fsf;
}