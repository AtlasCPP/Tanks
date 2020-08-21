#include "Window.h"

Window::Window() {
}

Window::~Window() {

}

void Window::createWindow(const char* const name) {
    _window.create
    (
        sf::VideoMode(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT),
        name
        );
}

sf::RenderWindow& Window::get_window() {
    return _window;
}

void Window::setView(view& v) {
    _window.setView(v.getView());
}

void Window::clear() {
    _window.clear(sf::Color::Black);
}

void Window::draw(const sf::Sprite& obj) {
    _window.draw(obj);
}

void Window::display() {
    _window.display();
}

void Window::close() {
    _window.close();
}