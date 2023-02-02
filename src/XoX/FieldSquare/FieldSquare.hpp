//
// Created by egorich on 26.01.23.
//

#ifndef XOXAI_FIELDSQUARE_HPP
#define XOXAI_FIELDSQUARE_HPP

#include <SFML/Graphics.hpp>

class FieldSquare {
private:
    sf::RectangleShape rectangle;
    bool highlighted = false;
public:
    int status = 0;     // 0 - empty; 1 - x; -1 - o;
    FieldSquare() = default;
    FieldSquare(float width, float height, float x, float y, float outline);
    FieldSquare(FieldSquare const & fs);
    bool is_pushed(sf::Vector2<int> point) const;
    void highlight(bool b);
    void draw(sf::RenderWindow * window) const;
};



#endif //XOXAI_FIELDSQUARE_HPP
