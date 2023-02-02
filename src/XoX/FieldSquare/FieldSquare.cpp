//
// Created by egorich on 26.01.23.
//

#include "FieldSquare.hpp"

FieldSquare::FieldSquare(float width, float height, float x, float y, float outline) {
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setOutlineThickness(outline);
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color(120, 175, 85));
    rectangle.setOutlineColor(sf::Color::Black);
    status = 0;
}

bool FieldSquare::is_pushed(sf::Vector2<int> point) const{
    return (rectangle.getPosition().x < point.x && point.x < rectangle.getPosition().x + rectangle.getSize().x
            && rectangle.getPosition().y < point.y && point.y < rectangle.getPosition().y + rectangle.getSize().y);
}


void FieldSquare::draw(sf::RenderWindow *window) const{

    window->draw(rectangle);
    float w = rectangle.getSize().x;
    float h = rectangle.getSize().y;
    float x = rectangle.getPosition().x;
    float y = rectangle.getPosition().y;

    if(status == 1 || status == 2){
        sf::VertexArray quad1(sf::Quads, 4);
        quad1[0].position = sf::Vector2f(x + w / 5, y + h / 10);
        quad1[1].position = sf::Vector2f(x + w / 10, y + h / 5);
        quad1[2].position = sf::Vector2f(x + 4 * w / 5, y + 9 * h / 10);
        quad1[3].position = sf::Vector2f(x + 9 * w / 10, y + 4 * h / 5);

        sf::VertexArray quad2(sf::Quads, 4);
        quad2[0].position = sf::Vector2f(x + 4 * w / 5, y + h / 10);
        quad2[1].position = sf::Vector2f(x + 9 * w / 10, y + h / 5);
        quad2[2].position = sf::Vector2f(x + w / 5, y + 9 * h / 10);
        quad2[3].position = sf::Vector2f(x + w / 10, y + 4 * h / 5);

        if (status == 1){
            for (int i = 0; i < 4; ++i){
                quad1[i].color = sf::Color(150, 0, 0);
                quad2[i].color = sf::Color(150, 0, 0);
            }
        }
        else{
            for (int i = 0; i < 4; ++i){
                quad1[i].color = sf::Color::Yellow;
                quad2[i].color = sf::Color::Yellow;
            }
        }
        window->draw(quad1);
        window->draw(quad2);
    }


    if(status == -1 || status == -2){
        sf::CircleShape Circ(rectangle.getSize().x / 3);
        Circ.setPosition(x + w / 6, y + h / 6);
        if (status == -1) Circ.setOutlineColor(sf::Color(0, 0, 150));
        else Circ.setOutlineColor(sf::Color::Yellow);
        Circ.setFillColor(sf::Color(0, 0, 0, 0));
        Circ.setOutlineThickness(w / 7);
        window->draw(Circ);
    }
}

FieldSquare::FieldSquare(const FieldSquare &fs) {
    rectangle = fs.rectangle;
    status = fs.status;
}

void FieldSquare::highlight(bool b) {
    highlighted = b;
    if (highlighted) rectangle.setFillColor(sf::Color(200, 200, 100));
    else rectangle.setFillColor(sf::Color(120, 175, 85));
}
