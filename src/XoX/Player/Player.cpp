//
// Created by egorich on 25.01.23.
//

#include "Player.hpp"

LinesAndChecks Player::count_lines_and_checks(const Matrix & matrix) const {
    LinesAndChecks res;

    int tmp_us = 0, tmp_op = 0;
    std::array <int, 3> tmp_check1{-1, -1, -1};
    std::array <int, 3> tmp_check2{-1, -1, -1};


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {

            // ----------------
            for (int k = 0; k < 4; ++k) {
                if (matrix.m[k][i][j] != 0) {
                    if (matrix.m[k][i][j] == side) tmp_us += 1;
                    else tmp_op += 1;
                }
                else {
                    if(tmp_check1[0] == -1){
                        tmp_check1 = {k, i, j};
                    }
                    else{
                        tmp_check2 = {k, i, j};
                    }
                }
            }
            if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
            if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
            if (tmp_op == 0 && tmp_us == 2){
                res.our_checks.emplace_back(tmp_check1);
                res.our_checks.emplace_back(tmp_check2);
            }
            if (tmp_us == 0 && tmp_op == 2){
                res.opp_checks.emplace_back(tmp_check1);
                res.opp_checks.emplace_back(tmp_check1);
            }
            tmp_check1 = {-1, -1, -1};
            tmp_check2 = {-1, -1, -1};
            tmp_us = 0;
            tmp_op = 0;

            // ----------------
            for (int k = 0; k < 4; ++k) {
                if (matrix.m[i][k][j] != 0) {
                    if (matrix.m[i][k][j] == side) tmp_us += 1;
                    else tmp_op += 1;
                }
                else {
                    if(tmp_check1[0] == -1){
                        tmp_check1 = {i, k, j};
                    }
                    else{
                        tmp_check2 = {i, k, j};
                    }
                }
            }
            if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
            if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
            if (tmp_op == 0 && tmp_us == 2){
                res.our_checks.emplace_back(tmp_check1);
                res.our_checks.emplace_back(tmp_check2);
            }
            if (tmp_us == 0 && tmp_op == 2){
                res.opp_checks.emplace_back(tmp_check1);
                res.opp_checks.emplace_back(tmp_check1);
            }
            tmp_check1 = {-1, -1, -1};
            tmp_check2 = {-1, -1, -1};
            tmp_us = 0;
            tmp_op = 0;

            // ----------------
            for (int k = 0; k < 4; ++k) {
                if (matrix.m[i][j][k] != 0) {
                    if (matrix.m[i][j][k] == side) tmp_us += 1;
                    else tmp_op += 1;
                }
                else {
                    if(tmp_check1[0] == -1){
                        tmp_check1 = {i, j, k};
                    }
                    else{
                        tmp_check2 = {i, j, k};
                    }
                }
            }
            if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
            if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
            if (tmp_op == 0 && tmp_us == 2){
                res.our_checks.emplace_back(tmp_check1);
                res.our_checks.emplace_back(tmp_check2);
            }
            if (tmp_us == 0 && tmp_op == 2){
                res.opp_checks.emplace_back(tmp_check1);
                res.opp_checks.emplace_back(tmp_check1);
            }
            tmp_check1 = {-1, -1, -1};
            tmp_check2 = {-1, -1, -1};
            tmp_us = 0;
            tmp_op = 0;
        }
    }

    for (int i = 0; i < 4; ++i) {

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[i][k][k] != 0) {
                if (matrix.m[i][k][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else {
                if(tmp_check1[0] == -1){
                    tmp_check1 = {i, k, k};
                }
                else{
                    tmp_check2 = {i, k, k};
                }
            }
        }
        if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
        if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
        if (tmp_op == 0 && tmp_us == 2){
            res.our_checks.emplace_back(tmp_check1);
            res.our_checks.emplace_back(tmp_check2);
        }
        if (tmp_us == 0 && tmp_op == 2){
            res.opp_checks.emplace_back(tmp_check1);
            res.opp_checks.emplace_back(tmp_check1);
        }
        tmp_check1 = {-1, -1, -1};
        tmp_check2 = {-1, -1, -1};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[i][3 - k][k] != 0) {
                if (matrix.m[i][3 - k][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else {
                if(tmp_check1[0] == -1){
                    tmp_check1 = {i, 3 - k, k};
                }
                else{
                    tmp_check2 = {i, 3 - k, k};
                }
            }
        }
        if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
        if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
        if (tmp_op == 0 && tmp_us == 2){
            res.our_checks.emplace_back(tmp_check1);
            res.our_checks.emplace_back(tmp_check2);
        }
        if (tmp_us == 0 && tmp_op == 2){
            res.opp_checks.emplace_back(tmp_check1);
            res.opp_checks.emplace_back(tmp_check1);
        }
        tmp_check1 = {-1, -1, -1};
        tmp_check2 = {-1, -1, -1};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[k][i][k] != 0) {
                if (matrix.m[k][i][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else {
                if(tmp_check1[0] == -1){
                    tmp_check1 = {k, i, k};
                }
                else{
                    tmp_check2 = {k, i, k};
                }
            }
        }
        if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
        if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
        if (tmp_op == 0 && tmp_us == 2){
            res.our_checks.emplace_back(tmp_check1);
            res.our_checks.emplace_back(tmp_check2);
        }
        if (tmp_us == 0 && tmp_op == 2){
            res.opp_checks.emplace_back(tmp_check1);
            res.opp_checks.emplace_back(tmp_check1);
        }
        tmp_check1 = {-1, -1, -1};
        tmp_check2 = {-1, -1, -1};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[3 - k][i][k] != 0) {
                if (matrix.m[3 - k][i][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else {
                if(tmp_check1[0] == -1){
                    tmp_check1 = {3 - k, i, k};
                }
                else{
                    tmp_check2 = {3 - k, i, k};
                }
            }
        }
        if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
        if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
        if (tmp_op == 0 && tmp_us == 2){
            res.our_checks.emplace_back(tmp_check1);
            res.our_checks.emplace_back(tmp_check2);
        }
        if (tmp_us == 0 && tmp_op == 2){
            res.opp_checks.emplace_back(tmp_check1);
            res.opp_checks.emplace_back(tmp_check1);
        }
        tmp_check1 = {-1, -1, -1};
        tmp_check2 = {-1, -1, -1};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[k][k][i] != 0) {
                if (matrix.m[k][k][i] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else {
                if(tmp_check1[0] == -1){
                    tmp_check1 = {k, k, i};
                }
                else{
                    tmp_check2 = {k, k, i};
                }
            }
        }
        if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
        if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
        if (tmp_op == 0 && tmp_us == 2){
            res.our_checks.emplace_back(tmp_check1);
            res.our_checks.emplace_back(tmp_check2);
        }
        if (tmp_us == 0 && tmp_op == 2){
            res.opp_checks.emplace_back(tmp_check1);
            res.opp_checks.emplace_back(tmp_check1);
        }
        tmp_check1 = {-1, -1, -1};
        tmp_check2 = {-1, -1, -1};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[3 - k][k][i] != 0) {
                if (matrix.m[3 - k][k][i] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else {
                if(tmp_check1[0] == -1){
                    tmp_check1 = {3 - k, k, i};
                }
                else{
                    tmp_check2 = {3 - k, k, i};
                }
            }
        }
        if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
        if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
        if (tmp_op == 0 && tmp_us == 2){
            res.our_checks.emplace_back(tmp_check1);
            res.our_checks.emplace_back(tmp_check2);
        }
        if (tmp_us == 0 && tmp_op == 2){
            res.opp_checks.emplace_back(tmp_check1);
            res.opp_checks.emplace_back(tmp_check1);
        }
        tmp_check1 = {-1, -1, -1};
        tmp_check2 = {-1, -1, -1};
        tmp_us = 0;
        tmp_op = 0;

    }

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[k][k][k] != 0) {
            if (matrix.m[k][k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else {
            if(tmp_check1[0] == -1){
                tmp_check1 = {k, k, k};
            }
            else{
                tmp_check2 = {k, k, k};
            }
        }
    }
    if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
    if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
    if (tmp_op == 0 && tmp_us == 2){
        res.our_checks.emplace_back(tmp_check1);
        res.our_checks.emplace_back(tmp_check2);
    }
    if (tmp_us == 0 && tmp_op == 2){
        res.opp_checks.emplace_back(tmp_check1);
        res.opp_checks.emplace_back(tmp_check1);
    }
    tmp_check1 = {-1, -1, -1};
    tmp_check2 = {-1, -1, -1};
    tmp_us = 0;
    tmp_op = 0;

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[3 - k][k][k] != 0) {
            if (matrix.m[3 - k][k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else {
            if(tmp_check1[0] == -1){
                tmp_check1 = {3 - k, k, k};
            }
            else{
                tmp_check2 = {3 - k, k, k};
            }
        }
    }
    if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
    if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
    if (tmp_op == 0 && tmp_us == 2){
        res.our_checks.emplace_back(tmp_check1);
        res.our_checks.emplace_back(tmp_check2);
    }
    if (tmp_us == 0 && tmp_op == 2){
        res.opp_checks.emplace_back(tmp_check1);
        res.opp_checks.emplace_back(tmp_check1);
    }
    tmp_check1 = {-1, -1, -1};
    tmp_check2 = {-1, -1, -1};
    tmp_us = 0;
    tmp_op = 0;

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[k][3 - k][k] != 0) {
            if (matrix.m[k][3 - k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else {
            if(tmp_check1[0] == -1){
                tmp_check1 = {k, 3 - k, k};
            }
            else{
                tmp_check2 = {k, 3 - k, k};
            }
        }
    }
    if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
    if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
    if (tmp_op == 0 && tmp_us == 2){
        res.our_checks.emplace_back(tmp_check1);
        res.our_checks.emplace_back(tmp_check2);
    }
    if (tmp_us == 0 && tmp_op == 2){
        res.opp_checks.emplace_back(tmp_check1);
        res.opp_checks.emplace_back(tmp_check1);
    }
    tmp_check1 = {-1, -1, -1};
    tmp_check2 = {-1, -1, -1};
    tmp_us = 0;
    tmp_op = 0;

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[3 - k][3 - k][k] != 0) {
            if (matrix.m[3 - k][3 - k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else {
            if(tmp_check1[0] == -1){
                tmp_check1 = {3 - k, 3 - k, k};
            }
            else{
                tmp_check2 = {3 - k, 3 - k, k};
            }
        }
    }
    if (tmp_op == 0 && tmp_us < 3) res.our_lines += tmp_us;
    if (tmp_us == 0 && tmp_op < 3) res.opp_lines += tmp_op;
    if (tmp_op == 0 && tmp_us == 2){
        res.our_checks.emplace_back(tmp_check1);
        res.our_checks.emplace_back(tmp_check2);
    }
    if (tmp_us == 0 && tmp_op == 2){
        res.opp_checks.emplace_back(tmp_check1);
        res.opp_checks.emplace_back(tmp_check1);
    }
//    tmp_check1 = {-1, -1, -1};
//    tmp_check2 = {-1, -1, -1};
//    tmp_us = 0;
//    tmp_op = 0;

    return res;
}


std::pair< std::array<int, 3>, int>  Player::can_win(const Matrix &matrix) const {
    int tmp_us = 0, tmp_op = 0;
    std::array <int, 3> res = {-1, -1, -1};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {

            // ----------------
            for (int k = 0; k < 4; ++k) {
                if (matrix.m[k][i][j] != 0) {
                    if (matrix.m[k][i][j] == side) tmp_us += 1;
                    else tmp_op += 1;
                }
                else res = {k, i, j};
            }
            if (tmp_op == 0 && tmp_us == 3) return {res, side};
            if (tmp_us == 0 && tmp_op == 3) return {res, -side};
            tmp_us = 0;
            tmp_op = 0;

            // ----------------
            for (int k = 0; k < 4; ++k) {
                if (matrix.m[i][k][j] != 0) {
                    if (matrix.m[i][k][j] == side) tmp_us += 1;
                    else tmp_op += 1;
                }
                else res = {i, k, j};
            }
            if (tmp_op == 0 && tmp_us == 3) return {res, side};
            if (tmp_us == 0 && tmp_op == 3) return {res, -side};
            tmp_us = 0;
            tmp_op = 0;

            // ----------------
            for (int k = 0; k < 4; ++k) {
                if (matrix.m[i][j][k] != 0) {
                    if (matrix.m[i][j][k] == side) tmp_us += 1;
                    else tmp_op += 1;
                }
                else res = {i, j, k};
            }
            if (tmp_op == 0 && tmp_us == 3) return {res, side};
            if (tmp_us == 0 && tmp_op == 3) return {res, -side};
            tmp_us = 0;
            tmp_op = 0;
        }
    }

    for (int i = 0; i < 4; ++i) {

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[i][k][k] != 0) {
                if (matrix.m[i][k][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else res = {i, k, k};
        }
        if (tmp_op == 0 && tmp_us == 3) return {res, side};
        if (tmp_us == 0 && tmp_op == 3) return {res, -side};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[i][3 - k][k] != 0) {
                if (matrix.m[i][3 - k][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else res = {i, 3 - k, k};
        }
        if (tmp_op == 0 && tmp_us == 3) return {res, side};
        if (tmp_us == 0 && tmp_op == 3) return {res, -side};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[k][i][k] != 0) {
                if (matrix.m[k][i][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else res = {k, i, k};
        }
        if (tmp_op == 0 && tmp_us == 3) return {res, side};
        if (tmp_us == 0 && tmp_op == 3) return {res, -side};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[3 - k][i][k] != 0) {
                if (matrix.m[3 - k][i][k] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else res = {3 - k, i, k};
        }
        if (tmp_op == 0 && tmp_us == 3) return {res, side};
        if (tmp_us == 0 && tmp_op == 3) return {res, -side};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[k][k][i] != 0) {
                if (matrix.m[k][k][i] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else res = {k, k, i};
        }
        if (tmp_op == 0 && tmp_us == 3) return {res, side};
        if (tmp_us == 0 && tmp_op == 3) return {res, -side};
        tmp_us = 0;
        tmp_op = 0;

        // ----------------
        for (int k = 0; k < 4; ++k) {
            if (matrix.m[3 - k][k][i] != 0) {
                if (matrix.m[3 - k][k][i] == side) tmp_us += 1;
                else tmp_op += 1;
            }
            else res = {3 - k, k, i};
        }
        if (tmp_op == 0 && tmp_us == 3) return {res, side};
        if (tmp_us == 0 && tmp_op == 3) return {res, -side};
        tmp_us = 0;
        tmp_op = 0;

    }

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[k][k][k] != 0) {
            if (matrix.m[k][k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else res = {k, k, k};
    }
    if (tmp_op == 0 && tmp_us == 3) return {res, side};
    if (tmp_us == 0 && tmp_op == 3) return {res, -side};
    tmp_us = 0;
    tmp_op = 0;

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[3 - k][k][k] != 0) {
            if (matrix.m[3 - k][k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else res = {3 - k, k, k};
    }
    if (tmp_op == 0 && tmp_us == 3) return {res, side};
    if (tmp_us == 0 && tmp_op == 3) return {res, -side};
    tmp_us = 0;
    tmp_op = 0;

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[k][3 - k][k] != 0) {
            if (matrix.m[k][3 - k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else res = {k, 3 - k, k};
    }
    if (tmp_op == 0 && tmp_us == 3) return {res, side};
    if (tmp_us == 0 && tmp_op == 3) return {res, -side};
    tmp_us = 0;
    tmp_op = 0;

    // ----------------
    for (int k = 0; k < 4; ++k) {
        if (matrix.m[3 - k][3 - k][k] != 0) {
            if (matrix.m[3 - k][3 - k][k] == side) tmp_us += 1;
            else tmp_op += 1;
        }
        else res = {3 - k, 3 - k, k};
    }
    if (tmp_op == 0 && tmp_us == 3) return {res, side};
    if (tmp_us == 0 && tmp_op == 3) return {res, -side};

//    tmp_check1 = {-1, -1, -1};
//    tmp_check2 = {-1, -1, -1};
//    tmp_us = 0;
//    tmp_op = 0;

    return {{-1, -1, -1}, 0};
}

std::array<int, 3> Player::make_move(const Field &field) const{
    Matrix matrix = field.bare_matrix();
    auto tmp_ = can_win(matrix);
    if (tmp_.second != 0){
        return tmp_.first;
    }
    int counts[4][4][4] = {0};
    int max = -1000;
    int max_index[3] = {0};

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){

                if(matrix.m[i][j][k] == 0){
                    matrix.m[i][j][k] = side;
                    auto tmp = count_lines_and_checks(matrix);
                    counts[i][j][k] = tmp.our_lines - tmp.opp_lines;
                    matrix.m[i][j][k] = 0;

                    if(max < counts[i][j][k]){
                        max = counts[i][j][k];
                        max_index[0] = i; max_index[1] = j; max_index[2] = k;
                    }

                }
            }
        }
    }

    return {max_index[0], max_index[1], max_index[2]};
}

Player::Player(int side) : side(side){}

void Player::set_side(int s) {
    side = s;
}

int Player::get_side() const {
    return side;
}
