#include <iostream>
#include <string>
#include <array>
#include <unordered_set>

void introduction() {
    std::cout << "WELCOME TO TIC-TAC-TOE!\n";

    std::cout << "===========\n";
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "===========\n\n";
    
    std::cout << "Player 1) ✖\n";
    std::cout << "Player 2) ⊙\n\n";

    std::cout << "Here's the 3 x 3 grid:\n\n";

    std::cout << "     |     |      \n";
    std::cout << " 0,0 | 0,1 | 0,2  \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << " 1,0 | 1,1 | 1,2  \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << " 2,0 | 2,1 | 2,2  \n";
    std::cout << "     |     |      \n\n";

    std::cout << "Press [Enter] to begin: ";
    std::cin.ignore();

    std::cout << "\n";
}

int symbol_to_player(char symbol) {
    if (symbol == 'x') {
        return 1;
    } else if (symbol == 'o') {
        return 2;
    } else {
        return 0;
    }
}

char player_to_symbol(int player) {
    if (player == 1) {
        return 'x';
    } else if (player == 2) {
        return 'o';
    } else {
        return ' ';
    }
}

void draw(char board[3][3]) {

    std::cout << "     |     |      \n";

    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}

std::array<int, 2> set_position(char board[3][3]) {
    std::array<int, 2> position;
    bool valid_move = false;
    
    std::cout << "\n";

    
    while (!valid_move) {
        std::cout << "Enter a row number between 0 and 2: ";
        while (!(std::cin >> position[0] && position[0] >=  0 && position[0] <= 2 )) {
            std::cout << "Please enter a valid number between 0 and 2: ";
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout << "Enter a column number between 0 and 2: ";
        while (!(std::cin >> position[1] && position[1] >=  0 && position[1] <= 2 )) {
            std::cout << "Please enter a valid number between 0 and 2: ";
            std::cin.clear();
            std::cin.ignore();
        }
        if (!(board[position[0]][position[1]] == ' ')) {
            std::cout << "Position is already taken. Try again. \n";
        } else {
            valid_move = true;
            std::cout << "Position Selected! Position: " << position[0] << ", " << position[1] << "\n";
        }
    }
    return position;
}

void update_board(char board[3][3], int turn, std::array<int, 2> position) {
    char sym;
    if (turn % 2) {
        sym = player_to_symbol(1);
    } else {
        sym = player_to_symbol(2);
    }
    board[position[0]][position[1]] = sym;
}

void take_turn(char board[3][3], int turn) {
    if (turn % 2) {
        std::cout << "PLAYER 1'S TURN: " << "\n";
    } else {
        std::cout << "PLAYER 2'S TURN: " << "\n";
    }
    std::array<int, 2> position = set_position(board);
    update_board(board, turn, position);
}

int change_player(int turn) {
    turn++;
    return turn;
}

int is_winner(char board[3][3]) {
    std::unordered_set<char> vals;
    char val;
    for (int row = 0; row < 3; row++) {
        vals.clear();
        for (int col = 0; col < 3; col++) {
            val = board[row][col];
            vals.insert(val);
            if (val == ' ' || vals.size() > 1) {
                break;
            }
            if (col == 2) {
                return symbol_to_player(val);
            }
        }
    }
    for (int col = 0; col < 3; col++) {
        vals.clear();
        for (int row = 0; row < 3; row++) {
            val = board[row][col];
            vals.insert(val);
            if (val == ' ' || vals.size() > 1) {
                break;
            }
            if (row == 2) {
                return symbol_to_player(val);
            }
        }
    }
    vals.clear();
    for (int i = 0; i < 3; i++) {
        val = board[i][i];
        vals.insert(val);
        if (val == ' ' || vals.size() > 1) {
            break;
        }
        if (i == 2) {
            return symbol_to_player(val);
        }
    }
    vals.clear();
    for (int i = 0; i < 3; i++) {
        val = board[2-i][i];
        vals.insert(val);
        if (val == ' ' || vals.size() > 1) {
            break;
        }
        if (i == 2) {
            return symbol_to_player(val);
        }
    }
    return 0;
}
bool filled_up(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void end_game(int winner) {
    if (winner == 1) {
        std::cout << "PLAYER 1 IS THE WINNER!\n";
    } else if (winner == 2) {
        std::cout << "PLAYER 2 IS THE WINNER!\n";
    } else {
        std::cout << "DRAW!\n";
    }
}