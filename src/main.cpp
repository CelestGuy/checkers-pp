#include <iostream>
#include "game/headers/game.h"

using namespace std;

int main()
{
    int board_size = 11;
    char player1_name[32] = "test1";
    char player2_name[32] = "test2";
    int tour = 1;
	
    game game_instance;
    game_instance.create_new_game(player1_name, player2_name, board_size);

	cout << "C'est parti !" << endl << game_instance.get_player1().get_name() << " vs " << game_instance.get_player2().get_name() << endl;
    cout << "Tour n" << tour << " !" << endl;
	
    while (!game_instance.update()) {
        tour++;
        cout << "Tour n" << tour << " !" << endl;
    }

    return 0;
}