#include "headers/piece.h"
#include "headers/colors.h"

piece::piece(colors piece_color, types piece_type)
{
    color = piece_color;
    type = piece_type;
	promoted = false;
}

piece::piece() {
	color = colors::NaC;
	type = types::NaP;
	promoted = false;
}

void piece::promote()
{
	promoted = true;
    type = KING;
}

void piece::demote() {
	promoted = false;
	type = PAWN;
}

bool piece::is_promoted()
{
    return promoted;
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