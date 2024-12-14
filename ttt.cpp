#include <iostream>
#include "ttt_functions.hpp"

int main() {
    introduction();
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    int turn = 1;
    while (!is_winner(board) && !filled_up(board)) {
        draw(board);
        take_turn(board, turn);
        turn = change_player(turn);
    }
    draw(board);
    end_game(is_winner(board));
}