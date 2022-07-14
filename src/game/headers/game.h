#include "board.h"
#include "player.h"

#pragma once

enum game_state
{
    PLAYER1_WON,
    PLAYER1_TURN,
    PLAYER2_WON,
    PLAYER2_TURN
};

class game
{
private:
    game_state has_winner;
    player player1;
    player player2;

    board game_board;
    void print_board();
    int get_piece_count(colors color);

public:
    game();
    ~game();

    void create_new_game(char *player1_name, char *player2_name, int board_size);

    void update();

    player get_player1();
    player get_player2();

    piece get_piece(int x, int y);
};