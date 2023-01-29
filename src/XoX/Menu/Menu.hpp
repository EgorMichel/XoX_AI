//
// Created by egorich on 27.01.23.
//

#ifndef XOXAI_MENU_HPP
#define XOXAI_MENU_HPP

#include "../Button/Button.hpp"

class Menu {
private:
    std::vector<Button> Buttons;
public:
    Menu() = default;
    Menu(float ScreenWidth, float ScreenHeight);
    void Draw(sf::RenderWindow *window);
    Button_Type click(sf::Vector2<int> point);
};


#endif //XOXAI_MENU_HPP
