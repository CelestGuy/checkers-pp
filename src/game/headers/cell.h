#include "piece.h"
#include "colors.h"

#pragma once

class cell
{
private:
    piece case_piece;
    colors color;

public:
    cell();
    ~cell();

    piece get_piece();
    colors get_color();

    void set_piece(piece new_piece);
    void set_color(colors case_color);
};
