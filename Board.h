//
// Created by Andrew Peterson on 8/1/2018.
//

#ifndef CLIONTEST_BOARD_H
#define CLIONTEST_BOARD_H

#include "iostream"
#include <vector>

class Board {
public:
    enum Square {
        None, Player1, Player2
    };
    Board();
    int checkWin();
    void setSquare(int row, int col, Square square);
    void printBoard();
    bool canSetSquare(int row, int col);
    bool checkTie();

private:
    std::vector<std::vector<Square>> rows;
    int checkRows();
    int checkCols();
    int checkDiagonals();
    void printSetNumberOfTimes(char character);
    const int printSize = 1;
};


#endif //CLIONTEST_BOARD_H
