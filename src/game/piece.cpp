#include "headers/piece.h"
#include "headers/colors.h"

piece::piece(colors piece_color, types piece_type)
{
    color = piece_color;
    type = piece_type;
}

piece::piece()
{
}

void piece::promote(types new_type)
{
    type = new_type;
}

bool piece::is_promoted()
{
    return can_be_promoted;
}

colors piece::get_color()
{
    return color;
}

types piece::get_type()
{
    return type;
}

piece::~piece()
{
}