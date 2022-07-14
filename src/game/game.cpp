#include "headers/game.h"
#include "headers/colors.h"
#include "headers/player.h"
#include "headers/board.h"
#include "headers/piece.h"
#include "headers/cell.h"

#include <iostream>

using namespace std;

game::game()
{
    this->game_status = WHITE_TURN;
    this->game_board = board();
    this->player1 = player("player1", WHITE);
    this->player2 = player("player2", BLACK);
}

void game::print_board()
{
    for (int i = 0; i < this->game_board.get_size(); i++)
    {
        for (int j = 0; j < this->game_board.get_size(); j++)
        {
            cell ccell = (* this->game_board.get_cell(j, i));
            if (ccell.get_color() == BLACK && ccell.is_empty())
            {
                cout << "  ";
            }
            else if (ccell.get_color() == WHITE && ccell.is_empty())
            {
                cout << "\033[30;47m  \033[0m";
            }
            else if (ccell.get_color() == BLACK && ccell.is_occupied())
            {
				piece p = (* ccell.get_piece());
                if (p.get_color() == WHITE) {
                    cout << "o ";
                }
                else if (p.get_color() == BLACK) {
                    cout << "x ";
                }
            }
        }
		cout << endl;
    }
}

void game::create_new_game(char *player1_name, char *player2_name, int board_size)
{
    this->game_board = board(board_size);
    this->player1 = player(player1_name, WHITE);
    this->player2 = player(player2_name, BLACK);

    for (int i = 0; i < game_board.get_size(); i++) {
        for (int j = 0; j < game_board.get_size(); j++) {
            cell ccell = (* game_board.get_cell(j, i));

            if (i < game_board.get_size() / 2 && ccell.get_color() == BLACK) {
                this->game_board.get_cell(j, i)->set_piece(new piece(colors::BLACK, types::PAWN));
            }
            else if (i > game_board.get_size() / 2 && ccell.get_color() == BLACK) {
				this->game_board.get_cell(j, i)->set_piece(new piece(colors::WHITE, types::PAWN));
            }
        }
    }
}

bool game::update()
{
    print_board();
    int black_piece_count = get_piece_count(BLACK);
    int white_piece_count = get_piece_count(WHITE);
    cell current_cell;
    piece* current_piece = nullptr;
	player current_player;
    bool cin_fail = false;

    if (black_piece_count == 0)
    {
        game_status = WHITE_WON;
    }
    else if (white_piece_count == 0)
    {
        game_status = BLACK_WON;
    }
    
    switch (game_status)
    {
        case WHITE_TURN:
            current_player = get_player1();
            break;
        case BLACK_TURN:
            current_player = get_player2();
            break;
        default:
            return true;
    }

    cout << "Au tour de " << current_player.get_name() << " !" << endl;
    cout << "Sa couleur est: " << current_player.get_color() << endl;

    do {
		string input;
        cout << "Entrez les coordonnées de la pièce à déplacer (x,y) : ";
        cin >> input;
        cin_fail = cin.fail();
        cin.clear();

		int x = input[0] - '0';
		int y = input[2] - '0';

		cout << x << " " << y << endl;

        cout << game_board.get_cell(x, y)->get_piece()->get_type() << endl;

        if (x < 0 || x > game_board.get_size() || y < 0 || y > game_board.get_size()) {
            cin_fail = true;
			cout << "Coordonnées invalides" << endl;
        }
        else if (game_board.get_cell(x, y)->is_empty()) {
			cin_fail = true;
			cout << "Case vide" << endl;
        }
        else if (game_board.get_cell(x, y)->get_piece()->get_color() != current_player.get_color()) {
			cin_fail = true;
			cout << "Cette pièce ne vous appartient pas ! (" <<
                game_board.get_cell(x, y)->get_piece()->get_color() << ")" << endl;
        }
        else {
            current_piece = game_board.get_cell(x, y)->get_piece();
        }
    }
	while (cin_fail);

        do {
            string input;
            cout << "Entrez les coordonnées de la destination (x,y) : ";
            cin >> input;
            cin_fail = cin.fail();
            cin.clear();

            int x = input[0] - '0';
            int y = input[2] - '0';

            if (x < 0 || x > game_board.get_size() || y < 0 || y > game_board.get_size()) {
                cin_fail = true;
                cout << "Coordonnées invalides !" << endl;
            }
            else if (game_board.get_cell(x, y)->is_occupied()) {
                cin_fail = true;
                cout << "Case occupée !" << endl;
            }
            else {
                game_board.get_cell(x, y)->set_piece(current_piece);
            }
        } while (cin_fail);

	

    return false;
}

int game::get_piece_count(colors color)
{
    int counter = 0;
    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < 2; x++)
        {
            if (this->game_board.get_cell(x, y)->get_color() == color)
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

piece game::get_piece(int x, int y)
{
	return (* this->game_board.get_cell(x, y)->get_piece());
}

game::~game()
{
    this->game_board = NULL;
}