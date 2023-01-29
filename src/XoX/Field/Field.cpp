//
// Created by egorich on 26.01.23.
//

#include "Field.hpp"

Field::Field(float ScreenWidth, float ScreenHeight) {
    const float height = ScreenHeight / 19;
    const float width = height;
    const float x0 = 1.5f * width;
    const float y0 = 0.5f * height;
    const float outline = width / 15;

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                FieldSquare tmp (width, height,(x0 + (width + outline) * float(k)), (y0 + (height + outline) * float(j) + height * 4.5f * float(i)), outline);
                matrix[i][j][k] = tmp;
            }
        }
    }
}

void Field::Draw(sf::RenderWindow *window) const{
    for(auto & i : matrix){
        for(auto & j : i){
            for(auto & k : j){
                k.draw(window);
            }
        }
    }

}

std::array<int, 3> Field::click(sf::Vector2<int> point) const {
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                if(matrix[i][j][k].is_pushed(point)){
                    return {i, j, k};
                }
            }
        }
    }
    return {-1, -1, -1};
}

void Field::refresh() {
    for(auto & i : matrix){
        for(auto & j : i){
            for(auto & k : j){
                k.status = 0;
            }
        }
    }
}

Field::Field(Field const &f) {
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                matrix[i][j][k] = FieldSquare(f.matrix[i][j][k]);
            }
        }
    }
}

Matrix Field::bare_matrix() const{
    Matrix tmp;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                tmp.m[i][j][k] = matrix[i][j][k].status;
            }
        }
    }
    return tmp;
}
