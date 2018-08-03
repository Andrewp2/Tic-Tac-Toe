//
// Created by Andrew Peterson on 8/1/2018.
//

#include "Board.h"

int Board::checkWin() {
    int result = checkRows();
    if (result == 0) {
        result = checkCols();
        if (result == 0) {
            result = checkDiagonals();
        }
    }
    return result;
}


void Board::setSquare(int row, int col, Square square) {
    if(rows[row][col] != None) {
        return;
    }
    else {
        rows[row][col] = square;
    }
}

void Board::printBoard() {
    for(int row = 0; row < rows.size()*printSize; row ++) {
        for(int col = 0; col < rows[row/printSize].size(); col++) {
            switch (rows[row/printSize][col]) {
                case None:
                    printSetNumberOfTimes('.');
                    break;
                case Player1:
                    printSetNumberOfTimes('X');
                    break;
                case Player2:
                    printSetNumberOfTimes('O');
                    break;
                default:
                    printSetNumberOfTimes('&');
                    break;
            }
        }
        std::cout << '\n';
    }
}

int Board::checkRows() {
    for(int row = 0; row < rows.size(); row++) {
        Square firstSquare = rows[row][0];
        int result = firstSquare;
        for(int col = 1; col < rows[row].size(); col ++) {
            if(firstSquare != rows[row][col]) {
                result = None;
            }
        }
        if(result != None) {
            return result;
        }
    }

    return None;
}

int Board::checkCols() {
    for(int col = 0; col < rows[0].size(); col++) {
        Square firstSquare = rows[0][col];
        int result = firstSquare;
        for(int row = 1; row < rows.size(); row++) {
            if(firstSquare != rows[row][col]) {
                result = None;
            }
        }
        if(result != None) {
            return result;
        }
    }
}

int Board::checkDiagonals() {
    Square topleft = rows[0][0];
    if(topleft == rows[1][1] && topleft == rows [2][2] && topleft != None) {
        return topleft;
    }
    Square topright = rows[0][2];
    if(topright == rows[1][1] && topright == rows[2][0] && topright) {
        return topright;
    }
    return None;
}

Board::Board() {
    rows = std::vector<std::vector<Square>>();
    for(int i = 0; i < 3; i++) {
        std::vector<Square> column(3, None);
        rows.push_back(column);
    }
}

bool Board::canSetSquare(int row, int col) {
    if(row < 0 || col < 0 || row >= rows.size() || col >= rows[0].size()) {
        return false;
    }
    return (rows[row][col] == None);
}

void Board::printSetNumberOfTimes(char character) {
    for(int i = 0; i < printSize; i++) {
        std::cout << character;
    }
}

bool Board::checkTie() {
    for(int row = 0; row < rows.size(); row++) {
        for(int col = 0; col < rows[0].size(); col++) {
            if(rows[row][col] == None) {
                return false;
            }
        }
    }
    return true;
}
