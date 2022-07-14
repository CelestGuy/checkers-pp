#include "board.h"
#include "player.h"

#pragma once

enum game_state
{
    WHITE_WON,
    WHITE_TURN,
    BLACK_WON,
    BLACK_TURN
};

class game
{
private:
    game_state game_status;
    player player1;
    player player2;

    board game_board;
    void print_board();
    int get_piece_count(colors color);

public:
    game();
    ~game();

    void create_new_game(char *player1_name, char *player2_name, int board_size);

    bool update();
    bool can_move(cell *cell_departure, cell *cell_arrival);

    player get_player1();
    player get_player2();

    piece get_piece(int x, int y);
};