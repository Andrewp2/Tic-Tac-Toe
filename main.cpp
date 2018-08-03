

#include "Board.h"

int main() {
    Board board;
    Board::Square turn = Board::Square::Player1;
    do {
        int row = -1;
        int col = -1;
        while(!(board.canSetSquare(row-1, col-1))) {
            std::cout << "Player " << turn << ": input a row and column number to make your move." << '\n';
            std::cin >> row >> col;
            if(std::cin.fail()){
                std::cout << "Error, int not entered" << '\n';
                row = -1;
                col = -1;
                std::cin.clear();
                std::cin.ignore(256,'\n');
            }
            else {
                std::cout << "Selected row and column: " << row << ", " << col << '\n';
            }
        }
        board.setSquare(row-1, col-1, turn);
        board.printBoard();
        turn = Board::Square (3 - turn);
    } while (board.checkWin() == 0 && !board.checkTie());

    if(board.checkWin() != 0) {
        std::cout << "Player " << board.checkWin() << " has won the game." << std::endl;
    }
    else {
        std::cout << "The game was a tie.";
    }
    return 0;
}

