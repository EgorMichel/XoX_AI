//
// Created by egorich on 25.01.23.
//

#ifndef XOXAI_TEST_PLAYER_HPP
#define XOXAI_TEST_PLAYER_HPP

#include <array>
#include <ctime>
#include <random>
#include <iostream>

#include "../Check_Win/Check_Win.hpp"

struct LinesAndChecks {
    int our_lines = 0;
    int opp_lines = 0;
    std::vector<std::array<int, 3>> our_checks;
    std::vector<std::array<int, 3>> opp_checks;
};



class Player {

private:

    int side = 0;

    [[nodiscard]] LinesAndChecks count_lines_and_checks(const Matrix & matrix) const; // [0] - lines for x, [1] - lines for o

    [[nodiscard]] std::pair< std::array<int, 3>, int> can_win(const Matrix & matrix) const;

    bool deep_analysis(const Matrix & field, int iteration, std::array<int, 3> * winning_move) const;

public:

    Player() = default;

    explicit Player(int side);

    void set_side(int side);

    [[nodiscard]] int get_side() const;

    /**
     * @returns an std::array<int, 3> coordinates of a move
     */
    [[nodiscard]] std::array<int, 3> make_move(const Field & f);
};


#endif //XOXAI_TEST_PLAYER_HPP
