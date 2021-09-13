#include "EmptyCell.h"
#include <string>

/**
 * @brief	Default constructor for empty cell
 *
 */

EmptyCell::EmptyCell() {
}

/**
 * @brief	Default destructor for empty cell
 *
 */

EmptyCell::~EmptyCell() {
}

/**
 * @brief	Evaluates the cell to a numeric value of zero
 *
 * @returns	Zero
 * 			
 */

double EmptyCell::evaluate() const {
	return 0.;
}

/**
 * @brief	Gives the string representation of the cell
 *
 * @returns	Empty string
 * 			
 */

std::string EmptyCell::toString() const {
	return "";
}