#include "ErrorCell.h"
#include <string>

/**
 * @brief	Default constructor for error cell
 *
 */

ErrorCell::ErrorCell() {
}

/**
 * @brief	Default destructor for error cell
 *
 */

ErrorCell::~ErrorCell() {
}

/**
 * @brief	Evaluates the cell to a numeric value of zero
 *
 * @returns	Zero
 *
 */

double ErrorCell::evaluate() const {
	return 0.;
}

/**
 * @brief	Gives the string representation of the cell
 *
 * @returns	'ERROR' string
 *
 */

std::string ErrorCell::toString() const {
	return "ERROR";
}


