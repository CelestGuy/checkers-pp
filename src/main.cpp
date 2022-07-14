#include <stdio.h>
#include "game/headers/game.h"

using namespace std;

int main()
{
    int board_size = 10;
    char player1_name[32] = "test1";
    char player2_name[32] = "test2";

    /*printf("Joueur 1 entrez votre nom: ");
    scanf("%s", &player1_name);
    printf("Joueur 2 entrez votre nom: ");
    scanf("%s", &player2_name);

    printf("Entrez la taille du plateau: ");
    scanf("%d", &board_size);*/

    game game_instance;
    game_instance.create_new_game(player1_name, player2_name, board_size);

    player player1 = game_instance.get_player1();
    player player2 = game_instance.get_player2();

    printf("%s vs %s\n", player1.get_player_name(), player2.get_player_name());

    game_instance.update();

    return 0;
}