#ifndef NUM_CELL_H
#define NUM_CELL_H

#include "Cell.h"
#include <string>

/**
 * @class	NumCell
 *
 * @brief	Class representing a table cell with a 64-bit floating data assigned.
 * 			Has only private constrcutor and cannot be manually instantiated.
 * 			Inherits abstract class cell and overrides all its virtual methods.
 *
 */
class NumCell :
	public Cell
{
	friend class Table;

public:
	double evaluate() const;
	std::string toString() const;
	~NumCell();
	
private:
	NumCell(double);

	/** 
	*@brief	Numeric value of the cell as a 64-bit floating data type
	*/
	double value;
};

#endif

