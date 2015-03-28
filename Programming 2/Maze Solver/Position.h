//Keith Monaghan
//Position.h

#include <iostream>
#include <string>
#include <stdexcept>

#ifndef POSITION_H
#define POSITION_H

class Position
{
	public:
	/**
	*	@post Position created with row and col values set.
	*/
	Position(int row, int col);

	/**
	*	@return row value
	*/
	int getRow() const;

	/**
	*	@return col value
	*/
	int getCol() const;

	private:
	int m_row;
	int m_col;
};

#endif