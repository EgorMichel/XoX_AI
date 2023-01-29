//
// Created by egorich on 26.01.23.
//

#ifndef XOXAI_TEST_GAME_HPP
#define XOXAI_TEST_GAME_HPP

#include <vector>
#include <array>

#include "../Field/Field.hpp"
#include "../Menu/Menu.hpp"
#include "../Player/Player.hpp"
#include "../Check_Win/Check_Win.hpp"


enum class Game_modes{
    TbD = 0,
    PvP = 1,
    PvA = 2,
    AvP = 3,
    AvA = 4,
    end = 5
};


class Game {
private:
    unsigned ScreenWidth = sf::VideoMode::getDesktopMode().width / 2;
    unsigned ScreenHeight = sf::VideoMode::getDesktopMode().height / 5 * 4;
    sf::RenderWindow window;

    Field field;
    Menu menu;
    Player player;
    Player player2;

    int current_player = 1; // (1) -- x; (-1) -- o

    Game_modes game_mode = Game_modes::TbD;

    std::vector< std::array<int, 3> > moves_history;

public:
    Game();
    void set_mode(Game_modes mode);
    Game_modes get_mode();
    Field get_field();

    void make_move(std::array<int, 3> move);
    bool isRunning();
    void Events();
    void Draw();
    void AI_Move();
};


#endif //XOXAI_TEST_GAME_HPP
