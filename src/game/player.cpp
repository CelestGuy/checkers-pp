#include "headers/player.h"

player::player(char *name)
{
    this->player_name = name;
    this->player_score = 0;
}

player::player()
{
    this->player_score = 0;
}

player::~player()
{
}

int player::get_player_score()
{
    return this->player_score;
}

char *player::get_player_name()
{
    return this->player_name;
}