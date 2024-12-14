#include <array>


void introduction();
void draw(char board[3][3]);
void update_board(char board[3][3], int turn, int position[2]);
void take_turn(char board[3][3], int turn);
int change_player(int turn);
std::array<int, 2> set_position(char board[3][3]);
int sym_to_player(char symbol);
int is_winner(char board[3][3]);
bool filled_up(char board[3][3]);
void end_game(int winner);