#pragma once
#include "colors.h"

class player
{
private:
    char *name;
    int score;
	colors color;

public:
    player(char *name, colors player_color);
    player();
    ~player();

    int get_score();
    char *get_name();

    void set_score(int score);
    void set_name(char *name);

    colors get_color();
};