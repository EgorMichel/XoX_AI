//
// Created by egorich on 26.01.23.
//

#ifndef XOXAI_FIELD_HPP
#define XOXAI_FIELD_HPP


#include <vector>
#include <array>
#include "../FieldSquare/FieldSquare.hpp"

struct Matrix {
    int m[4][4][4] = {0};
};

struct Field {
    FieldSquare matrix[4][4][4];
public:
    Field() = default;
    Field(float ScreenWidth, float ScreenHeight);
    Field(Field const &f);
    void Draw(sf::RenderWindow * window) const;
    std::array<int, 3> click(sf::Vector2<int> point) const;
    Matrix bare_matrix() const;
    void refresh();
};


#endif //XOXAI_FIELD_HPP
