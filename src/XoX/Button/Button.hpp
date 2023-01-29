//
// Created by egorich on 26.01.23.
//

#ifndef XOXAI_BUTTON_HPP
#define XOXAI_BUTTON_HPP

#include <SFML/Graphics.hpp>


enum class Button_Type{
    None = 0,
    PvP = 1,
    PvA = 2,
    AvP = 3,
    AvA = 4,
    Back = 5,
    Fwd = 6
};


class Button {
protected:
    sf::RectangleShape rectangle;
    Button_Type type = Button_Type::None;
    bool status;
public:
    Button(float Width, float Height, float x, float y, sf::Color color, Button_Type type);
    bool is_pushed(sf::Vector2<int> point);
    void draw(sf::RenderWindow * window);
    void set_status(bool stat);
    bool get_status() const;
    Button_Type get_type();
};



#endif //XOXAI_BUTTON_HPP
