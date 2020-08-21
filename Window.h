#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H


#include "Constants.h"
#include "View.h"
/*
    Класс, который представляет главное окно
*/

class Window {
private:
    sf::RenderWindow _window;
protected:
public:
    Window();
    ~Window();

    void createWindow(const char* const);
    sf::RenderWindow& get_window();

    void setView(view&);
    /*
        Функция-обертка для clear() из sfml
    */
    void clear();
    /*
        Функция-обертка для draw() из sfml
    */
    void draw(const sf::Sprite&);
    /*
        Функция-обертка для display() из sfml
    */
    void display();
    /*
        Функция-обертка для close() из sfml
    */
    void close();
};

#endif
