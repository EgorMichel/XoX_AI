//
// Created by egorich on 26.01.23.
//

#include "Button.hpp"


bool Button::is_pushed(sf::Vector2<int> point) {
    return (rectangle.getPosition().x < point.x && point.x < rectangle.getPosition().x + rectangle.getSize().x
    && rectangle.getPosition().y < point.y && point.y < rectangle.getPosition().y + rectangle.getSize().y);
}

Button::Button(float width, float height, float x, float y, sf::Color color, Button_Type type_) {
    type = type_;
    status = false;
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setOutlineThickness(height / 15);
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow *window) {
    window->draw(rectangle);
}

Button_Type Button::get_type(){
    return type;
}

void Button::set_status(bool stat) {
    status = stat;
    if (status){
        rectangle.setOutlineColor(sf::Color::Yellow);
    }
    else{
        rectangle.setOutlineColor(sf::Color::Black);
    }
}

bool Button::get_status() const {
    return status;
}
