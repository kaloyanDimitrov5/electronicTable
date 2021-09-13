#ifndef CELL_H
#define CELL_H

#include <string>

/**
 * @class	Cell
 *
 * @brief	 Pure abstract class representing a table cell. Class cannot
 * 			 be instantinated and possess only virtual methods that 
 * 			 must be overriden in all derived classes
 *
 */

class Cell
{
public:

	/**
	 * @brief	 Pure virtual function to evaluate the cell.
	 * 			 Should be implemented in derived base class
	 *
	 * @returns	 A floating-point value of cell
	 */

	virtual double evaluate() const = 0;

	/**
	 * @brief	Gives the string representation of a cell
	 * 			Pure virtual function that should be 
	 * 			implemented in derived base class
	 *
	 * @returns	A string that represents this object
	 */

	virtual std::string toString() const = 0;

	virtual ~Cell();
};

#endif

