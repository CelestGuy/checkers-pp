#include "headers/player.h"
#include "headers/colors.h"

player::player(char *name, colors color)
{
    this->name = name;
    this->score = 0;
	this->color = color;
}

player::player() 
{	
}

player::~player()
{
}

int player::get_score()
{
    return this->score;
}

char *player::get_name()
{
    return this->name;
}


void player::set_score(int score) {
	this->score = score;
}

void player::set_name(char* name) {
	this->name = name;
}

colors player::get_color() {
	return this->color;
}

