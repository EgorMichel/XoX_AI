//
// Created by egorich on 26.01.23.
//

#include "Game.hpp"


Game::Game() :
    window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "XoX"){
    field = Field(ScreenWidth, ScreenHeight);
    menu = Menu(ScreenWidth, ScreenHeight);
}


void Game::set_mode(Game_modes mode) {
    game_mode = mode;
}

Game_modes Game::get_mode() {
    return game_mode;
}

Field Game::get_field() {
    return field;
}


void Game::make_move(std::array<int, 3> move) {

    if (field.matrix[move[0]][move[1]][move[2]].status == 0){
        field.matrix[move[0]][move[1]][move[2]].status = current_player;
        moves_history.emplace_back(move);
        auto win_line = CheckWin(field.bare_matrix());
        if (win_line[0][0] != -1){
            for (auto p : win_line){
                field.matrix[p[0]][p[1]][p[2]].status = current_player * 2;
            }
            game_mode = Game_modes::end;
            current_player = 0;
            return;
        }
        bool is_zeros = false;
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j){
                for (int k = 0; k < 4; ++k){
                    if(field.matrix[i][j][k].status == 0) is_zeros = true;
                }
            }
        }
        if (!is_zeros){
            game_mode = Game_modes::end;
        }
        current_player *= -1;
    }
}

void Game::Events() {
    sf::Event event{};
    while (window.pollEvent(event)){
        // check the type of the event...
        switch (event.type)
        {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;

                // key pressed
            case sf::Event::MouseButtonPressed:

                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2<int> position (event.mouseButton.x, event.mouseButton.y);

                    auto c_s = field.click(position);
                    switch (game_mode) {

                        case Game_modes::TbD:
                            break;

                        case Game_modes::PvP:
                            if (c_s[0] != -1) make_move(c_s);
                            break;

                        case Game_modes::PvA:
                            if (current_player == 1){
                                if (c_s[0] != -1) make_move(c_s);
                            }
                            break;

                        case Game_modes::AvP:
                            if (current_player == -1){
                                if (c_s[0] != -1) make_move(c_s);
                            }
                            break;

                        case Game_modes::AvA:
                            break;

                        case Game_modes::end:
                            break;

                    }


                    Button_Type tmp = menu.click(position);
                    switch (tmp) {
                        case Button_Type::PvP:
                            game_mode = Game_modes::PvP;
                            player.set_side(0);
                            field.refresh();
                            current_player = 1;
                            break;

                        case Button_Type::PvA:
                            game_mode = Game_modes::PvA;
                            player.set_side(-1);
                            field.refresh();
                            current_player = 1;
                            break;

                        case Button_Type::AvP:
                            game_mode = Game_modes::AvP;
                            player.set_side(1);
                            field.refresh();
                            current_player = 1;
                            break;

                        case Button_Type::AvA:
                            game_mode = Game_modes::AvA;
                            player.set_side(1);
                            player2.set_side(-1);
                            field.refresh();
                            current_player = 1;
                            break;

                        case Button_Type::Back:
                            break;

                        case Button_Type::Fwd:
                            break;

                        case Button_Type::None:
                            break;

                    }

                }
                break;

                // we don't process other types of events
            default:
                break;
        }
    }
}

void Game::Draw() {
    window.clear(sf::Color(10, 95, 56));
    field.Draw(&window);
    menu.Draw(&window);
    sf::Font font;
    window.display();
}

bool Game::isRunning() {
    return window.isOpen();
}

void Game::AI_Move() {
    switch (game_mode) {

        case Game_modes::TbD:
            break;

        case Game_modes::PvP:
            break;

        case Game_modes::PvA:
            if (current_player == -1){
                make_move(player.make_move(field));
            }
            break;

        case Game_modes::AvP:
            if (current_player == 1){
                make_move(player.make_move(field));
            }
            break;

        case Game_modes::AvA:
            if (current_player == 1){
                make_move(player.make_move(field));
            }
            if (current_player == -1){
                make_move(player2.make_move(field));
            }
            break;

        case Game_modes::end:
            break;

    }

}


