#include "headers/game.h"
#include "headers/colors.h"
#include "headers/player.h"
#include "headers/board.h"
#include "headers/piece.h"

#include <stdio.h>

game::game()
{
    this->game_board = board();
    this->player1 = player();
    this->player2 = player();
}

void game::print_board()
{
    for (int i = 0; i < this->game_board.get_board_size(); i++)
    {
        for (int j = 0; j < this->game_board.get_board_size(); j++)
        {
            if (this->game_board.get_cell(j, i).get_color() == BLACK)
            {
                printf("%s", "  ");
            }
            else if (this->game_board.get_cell(j, i).get_color() == WHITE)
            {
                printf("%s", "\033[30;47m  \033[0m");
            }
        }
        printf("\n");
    }
}

void game::create_new_game(char *player1_name, char *player2_name, int board_size)
{
    this->game_board = board(board_size);
    this->player1 = player(player1_name);
    this->player2 = player(player2_name);
}

void game::update()
{
    has_winner = PLAYER1_TURN;
    while (has_winner == PLAYER1_TURN || has_winner == PLAYER2_TURN)
    {
        int black_piece_count = get_piece_count(BLACK);
        int white_piece_count = get_piece_count(WHITE);

        if (black_piece_count == 0)
        {
            has_winner = PLAYER1_WON;
        }
        else if (white_piece_count == 0)
        {
            has_winner = PLAYER2_WON;
        }
    }
}

int game::get_piece_count(colors color)
{
    int counter = 0;
    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < 2; x++)
        {
            if (this->game_board.get_cell(x, y).get_color() == color)
            {
                counter++;
            }
        }
    }
    return counter;
}

player game::get_player1()
{
    return this->player1;
}

player game::get_player2()
{
    return this->player2;
}

game::~game()
{
}