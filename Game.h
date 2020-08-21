#ifndef GAME_H
#define GAME_H

#include "Enemy.h"          // класс врага
#include "Player.h"			// класс главного игрока
#include "Map.h"			// класс карты
#include "View.h"           // класс камеры
#include "Bullet.h"         // класс пули
#include "Window.h"
#include "Constants.h"
#include <list>
#include <iostream>


class Game {
private:
	view _view;
	Map _map;
	Window _window;
	Player _player;
	std::list<Enemy> _enemyList;
	bool _endGame;
	sf::Clock _clock;
	sf::Event _event;
protected:
public:
	Game();
	~Game();
	/*
		Инициализация всех полей
		необходимыми начальными
		значениями
	*/
	void Setup();
	/*
		Методы Input(),
		Logic() и Draw() - будут
		использоваться только
		в методе Run()
	*/
	/*
		Input() - выполняет
		обработку ввода пользователя
	*/
	void Input();
	/*
		Logic() - реализует логику
		игры
	*/
	void Logic();
	/*
		Draw() - выполняет отрисовку
		и вывод на экран с помощью 
		метода _window.display()
	*/
	void Draw();
	/*
		Run() - выполняет запуск 
		игрового цикла
	*/
	void Run();
	/*
		Обработчик движений врагов
		Реализует движение противников
	*/
	void enemyMovementHandler();
	/*
		Обработчик столкновений
		Реализует столкновения объектов
	*/
	void collisionHandler();
};

#endif