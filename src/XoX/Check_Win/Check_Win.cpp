//
// Created by egorich on 26.01.23.
//

#include "Check_Win.hpp"


std::array< std::array< int, 3 >, 4 > CheckWin(const Matrix& matrix){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if (matrix.m[0][i][j] == matrix.m[1][i][j] &&
                matrix.m[1][i][j] == matrix.m[2][i][j] &&
                matrix.m[2][i][j] == matrix.m[3][i][j] && matrix.m[3][i][j] != 0)
                return {{ {0, i, j}, {1, i, j}, {2, i, j}, {3, i, j} }};

            if (matrix.m[i][0][j] == matrix.m[i][1][j] &&
                matrix.m[i][1][j] == matrix.m[i][2][j] &&
                matrix.m[i][2][j] == matrix.m[i][3][j] && matrix.m[i][3][j] != 0)
                return {{ {i, 0, j}, {i, 1, j}, {i, 2, j}, {i, 3, j} }};

            if (matrix.m[i][j][0] == matrix.m[i][j][1] &&
                matrix.m[i][j][1] == matrix.m[i][j][2] &&
                matrix.m[i][j][2] == matrix.m[i][j][3] && matrix.m[i][j][3] != 0)
                return {{ {i, j, 0}, {i, j, 1}, {i, j, 2}, {i, j, 3} }};
        }
    }

    for (int i = 0; i < 4; ++i){
        if (matrix.m[i][0][0] == matrix.m[i][1][1] &&
            matrix.m[i][1][1] == matrix.m[i][2][2] &&
            matrix.m[i][2][2] == matrix.m[i][3][3] && matrix.m[i][0][0] != 0)
            return {{ {i, 0, 0}, {i, 1, 1}, {i, 2, 2}, {i, 3, 3} }};

        if (matrix.m[i][3][0] == matrix.m[i][2][1] &&
            matrix.m[i][2][1] == matrix.m[i][1][2] &&
            matrix.m[i][1][2] == matrix.m[i][0][3] && matrix.m[i][3][0] != 0)
            return {{ {i, 3, 0}, {i, 2, 1}, {i, 1, 2}, {i, 0, 3} }};


        if (matrix.m[0][i][0] == matrix.m[1][i][1] &&
            matrix.m[1][i][1] == matrix.m[2][i][2] &&
            matrix.m[2][i][2] == matrix.m[3][i][3] && matrix.m[0][i][0] != 0)
            return {{ {0, i, 0}, {1, i, 1}, {2, i, 2}, {3, i, 3} }};

        if (matrix.m[3][i][0] == matrix.m[2][i][1] &&
            matrix.m[2][i][1] == matrix.m[1][i][2] &&
            matrix.m[1][i][2] == matrix.m[0][i][3] && matrix.m[3][i][0] != 0)
            return {{ {3, i, 0}, {2, i, 1}, {1, i, 2}, {0, i, 3} }};


        if (matrix.m[0][0][i] == matrix.m[1][1][i] &&
            matrix.m[1][1][i] == matrix.m[2][2][i] &&
            matrix.m[2][2][i] == matrix.m[3][3][i] && matrix.m[0][0][i] != 0)
            return {{ {0, 0, i}, {1, 1, i}, {2, 2, i}, {3, 3, i} }};

        if (matrix.m[3][0][i] == matrix.m[2][1][i] &&
            matrix.m[2][1][i] == matrix.m[1][2][i] &&
            matrix.m[1][2][i] == matrix.m[0][3][i] && matrix.m[3][0][i] != 0)
            return {{ {3, 0, i}, {2, 1, i}, {1, 2, i}, {3, 0, i} }};
    }

    if (matrix.m[0][0][0] == matrix.m[1][1][1] &&
        matrix.m[2][2][2] == matrix.m[1][1][1] &&
        matrix.m[2][2][2] == matrix.m[3][3][3] && matrix.m[0][0][0] != 0)
        return {{ {0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {3, 3, 3} }};

    if (matrix.m[3][0][0] == matrix.m[2][1][1] &&
        matrix.m[1][2][2] == matrix.m[2][1][1] &&
        matrix.m[1][2][2] == matrix.m[0][3][3] && matrix.m[3][0][0] != 0)
        return {{ {3, 0, 0}, {2, 1, 1}, {1, 2, 2}, {0, 3, 3} }};

    if (matrix.m[0][3][0] == matrix.m[1][2][1] &&
        matrix.m[2][1][2] == matrix.m[1][2][1] &&
        matrix.m[2][1][2] == matrix.m[3][0][3] && matrix.m[0][3][0] != 0)
        return {{ {0, 3, 0}, {1, 2, 1}, {2, 1, 2}, {3, 0, 3} }};

    if (matrix.m[3][3][0] == matrix.m[2][2][1] &&
        matrix.m[1][1][2] == matrix.m[2][2][1] &&
        matrix.m[2][2][1] == matrix.m[0][0][3] && matrix.m[0][0][3] != 0)
        return {{ {3, 3, 0}, {2, 2, 1}, {1, 1, 2}, {0, 0, 3} }};

    return {{ {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} }};
}