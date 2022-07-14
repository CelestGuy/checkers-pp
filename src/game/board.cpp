#include "headers/board.h"
#include "headers/piece.h"
#include "headers/colors.h"
#include "headers/cell.h"

#include <stdio.h>

using namespace std;

board::board()
{
    for (int i = 0; i < CHECKERS_BOARD_SIZE; i++)
    {
        for (int j = 0; j < CHECKERS_BOARD_SIZE; j++)
        {
            this->board_cell[i][j] = cell();
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    this->board_cell[i][j].set_color(WHITE);
                }
                else
                {
                    this->board_cell[i][j].set_color(BLACK);
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    this->board_cell[i][j].set_color(BLACK);
                }
                else
                {
                    this->board_cell[i][j].set_color(WHITE);
                }
            }
        }
    }

    this->size = CHECKERS_BOARD_SIZE;
}

board::board(int board_size)
{
    if (board_size != 12 && board_size != 10 && board_size != 8)
    {
        printf("Taille de tableau invalide, utilisez 12, 10 ou 8\n");
        board_size = CHECKERS_BOARD_SIZE;
    }
    else
    {
        this->size = board_size;
    }

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            this->board_cell[i][j] = cell();
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    this->board_cell[i][j].set_color(WHITE);
                }
                else
                {
                    this->board_cell[i][j].set_color(BLACK);
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    this->board_cell[i][j].set_color(BLACK);
                }
                else
                {
                    this->board_cell[i][j].set_color(WHITE);
                }
            }
        }
    }
}

int board::get_board_size()
{
    return size;
}

cell board::get_cell(int x, int y)
{
    return this->board_cell[y][x];
}

piece board::get_piece(int x, int y)
{
    return this->board_cell[x][y].get_piece();
}

board::~board()
{
}