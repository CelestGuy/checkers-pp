#pragma once

class player
{
private:
    char *player_name;
    int player_score;

public:
    player(char *name);
    player();
    ~player();

    int get_player_score();
    char *get_player_name();

    void set_player_score(int score);
    void set_player_name(char *name);
};