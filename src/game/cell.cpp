#include "headers/cell.h"
#include "headers/piece.h"

cell::cell()
{
    this->color = NaC;
	this->cell_piece = new piece();
}

cell::~cell()
{
}

piece *cell::get_piece()
{
    return this->cell_piece;
}

colors cell::get_color()
{
    return this->color;
}

void cell::set_piece(piece* new_piece)
{
    this->cell_piece = new_piece;
}

void cell::set_color(colors case_color)
{
    this->color = case_color;
}

bool cell::is_empty()
{
	if (this->cell_piece == nullptr)
		return true;
	else {
		return this->cell_piece->get_type() == types::NaP;
	}
}

bool cell::is_occupied() {
	return !this->is_empty();
}