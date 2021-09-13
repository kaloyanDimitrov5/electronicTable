#ifndef EMPTY_CELL_H
#define EMPTY_CELL_H

#include "Cell.h"
#include <string>

/**
 * @class	EmptyCell
 *
 * @brief	Class representing an empty table cell with no value assigned yet.
 * 			Has only private constrcutor and cannot be manually instantiated.
 * 			Inherits abstract class cell and overrides all its virtual methods
 *
 */

class EmptyCell :
	public Cell
{
	friend class Table;
public:
	double evaluate() const;
	std::string toString() const;
	~EmptyCell();

private:
	EmptyCell();
};

#endif

