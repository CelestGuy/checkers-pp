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
    bool can_be_promoted;
    colors color;
    types type;

public:
    piece(colors piece_color, types piece_type);
    piece();
    ~piece();

    void promote(types new_type);
    bool is_promoted();

    colors get_color();
    types get_type();
};