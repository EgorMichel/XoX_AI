//
// Created by egorich on 27.01.23.
//

#include "Menu.hpp"


Menu::Menu(float ScreenWidth, float ScreenHeight){
    float x0 = ScreenWidth / 2;
    float y0 = ScreenHeight / 19 / 2;
    float h = ScreenHeight / 19;
    float w = ScreenWidth / 5 * 2;
    float y_shift = ScreenHeight / 19 + y0;

    Buttons.push_back(Button(w, h, x0, y0, sf::Color(200, 100, 100),
                             Button_Type::PvP, "Player vs Player"));
    Buttons.push_back(Button(w / 3, h, x0, y0 + y_shift,sf::Color(100, 200, 100),
                             Button_Type::PvA, "PvA"));
    Buttons.push_back(Button(w / 3, h, x0 + w / 3 * 2, y0 + y_shift, sf::Color(100, 200, 100),
                             Button_Type::AvP, "AvP"));
    Buttons.push_back(Button(w, h, x0, y0 + 2 * y_shift, sf::Color(100, 100, 200),
                             Button_Type::AvA, "AvA"));
    Buttons.push_back(Button(h, h, x0, ScreenHeight - y0 * 4, sf::Color(100, 100, 100),
                             Button_Type::Back, "<-"));
    Buttons.push_back(Button(h, h, x0 + ScreenWidth / 5 * 2 - y0 * 2, ScreenHeight - y0 * 4, sf::Color(100, 100, 100),
                             Button_Type::Fwd, "->"));


//    Buttons.emplace_back(w, h, x0, y0,
//                         sf::Color(200, 100, 100), Button_Type::PvP, "Player vs Player");
//    Buttons.emplace_back(w / 3, h, x0, y0 + y_shift,
//                         sf::Color(100, 200, 100), Button_Type::PvA, "PvA");
//    Buttons.emplace_back(w / 3, h, x0 + w / 3 * 2, y0 + y_shift,
//                         sf::Color(100, 200, 100), Button_Type::AvP, "AvP");
//    Buttons.emplace_back(w, h, x0, y0 + 2 * y_shift,
//                         sf::Color(100, 100, 200), Button_Type::AvA, "AvA");
//    Buttons.emplace_back(h, h, x0, ScreenHeight - y0 * 4,
//                         sf::Color(100, 100, 100), Button_Type::Back, "<-");
//    Buttons.emplace_back(h, h, x0 + ScreenWidth / 5 * 2 - y0 * 2, ScreenHeight - y0 * 4,
//                         sf::Color(100, 100, 100), Button_Type::Fwd, "->");

}

void Menu::Draw(sf::RenderWindow *window) {
//    for (int i = 0; i < Buttons.size(); ++i){
//        Buttons[i].draw(window);
//    }
    for (auto b : Buttons){
        b.draw(window);
    }
}

Button_Type Menu::click(sf::Vector2<int> point) {
    for (int i = 0; i < Buttons.size(); ++i){
        if(Buttons[i].is_pushed(point)){
            for (int j = 0; j < Buttons.size(); ++j){
                Buttons[j].set_status(false);
            }
            Buttons[i].set_status(true);
            return Buttons[i].get_type();
        }
    }
    return Button_Type::None;
}
