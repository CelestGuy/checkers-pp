#include "headers/cell.h"
#include "headers/piece.h"

cell::cell()
{
    this->color = NaC;
}

cell::~cell()
{
}

piece cell::get_piece()
{
    return this->case_piece;
}

colors cell::get_color()
{
    return this->color;
}

void cell::set_piece(piece new_piece)
{
    this->case_piece = piece(new_piece.get_color(), new_piece.get_type());
}

void cell::set_color(colors case_color)
{
    this->color = case_color;
}