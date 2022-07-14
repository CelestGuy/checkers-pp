#define CHECKERS_BOARD_SIZE 10

#include "piece.h"
#include "cell.h"

#pragma once

class board
{
private:
    int size;
    cell board_cell[CHECKERS_BOARD_SIZE][CHECKERS_BOARD_SIZE];

public:
    board();
    board(int board_size);
    ~board();

    int get_board_size();

    piece get_piece(int x, int y);
    cell get_cell(int x, int y);
};