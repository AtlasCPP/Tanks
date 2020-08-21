#include "View.h"

view::view() {
	_view.reset(
		sf::FloatRect(
			0,
			0,
			constants::WINDOW_WIDTH,
			constants::WINDOW_HEIGHT
			)
		);
}

view::~view() {

}

void view::setCenterCam(coordinate::Coordinate& C) {
	double x = C.x, y = C.y;
	if (x > (
		constants::MAP_WIDTH * constants::CARD_BLOCK_SIDE_SIZE 
		- constants::WINDOW_WIDTH / 2 - 68
			)
	   ) 
	{
		x = constants::MAP_WIDTH * constants::CARD_BLOCK_SIDE_SIZE 
		- constants::WINDOW_WIDTH / 2 - 68;
	}
	if (x < constants::WINDOW_WIDTH / 2) {
		x = constants::WINDOW_WIDTH / 2;
	}
	if (y > (
		constants::MAP_HEIGHT * constants::CARD_BLOCK_SIDE_SIZE
		- constants::WINDOW_HEIGHT / 2 - 64
			)
	   )
	{
		y = constants::MAP_HEIGHT * constants::CARD_BLOCK_SIDE_SIZE
		- constants::WINDOW_HEIGHT / 2 - 64;
	}
	if (y < constants::WINDOW_HEIGHT / 2) {
		y = constants::WINDOW_HEIGHT / 2;
	}
	_view.setCenter(x, y);
}

sf::View& view::getView() {
	return _view;
}