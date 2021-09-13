#ifndef TEXT_CELL_H
#define TEXT_CELL_H

#include "Cell.h"
#include <string>

/**
 * @class	TextCell
 *
 * @brief	Class representing a table cell assigned to a text.
 * 			Has only private constrcutor and cannot be manually instantiated.
 * 			Inherits abstract class cell and overrides all its virtual methods.
 *
 */
class TextCell :
	public Cell
{
	friend class Table;
public:
	double evaluate() const;
	std::string toString() const;
	~TextCell();

private:
	TextCell(const std::string&);


	/**  
	* @brief Text value of the cell
	*/
	std::string str;
};

#endif

