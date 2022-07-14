#include "colors.h"

#pragma once

enum types
{
    KING,
    PAWN,
    NaP
};

class piece
{
private:
    bool promoted;
    colors color;
    types type;

public:
    piece(colors piece_color, types piece_type);
    piece();
    ~piece();

    void promote();
	void demote();
    bool is_promoted();

    colors get_color();
    types get_type();
};