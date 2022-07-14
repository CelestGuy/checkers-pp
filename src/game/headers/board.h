#define CHECKERS_BOARD_SIZE 11

#include "piece.h"
#include "cell.h"

#pragma once

class board
{
private:
    int size;
    cell *board_cell[CHECKERS_BOARD_SIZE][CHECKERS_BOARD_SIZE];

public:
    board();
    board(int board_size);
    ~board();

    int get_size();

    cell *get_cell(int x, int y);
};