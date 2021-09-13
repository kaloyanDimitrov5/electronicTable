#ifndef ERROR_CELL_H
#define ERROR_CELL_H

#include "Cell.h"
#include <string>

/**
 * @class	ErrorCell
 *
 * @brief	Class representing an error table cell with a value that cant be resolved.
 * 			Has only private constrcutor and cannot be manually instantiated. 
 * 			Inherits abstract class cell and overrides all its virtual methods. 
 *
 */
class ErrorCell :
	public Cell
{
	friend class Table;
public:
	double evaluate() const;
	std::string toString() const;
	~ErrorCell();

private:
	ErrorCell();
};

#endif



