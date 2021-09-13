#include "NumCell.h"
#include <iomanip>
#include <string>
#include <sstream>

/**
 * @brief			Constucts a number cell from given numeric value
 *
 * @param [in]	d	Numeric value
 * 				
 */

NumCell::NumCell(double d) : value(d) {
}

/**
 * @brief	Default destructor for number cell
 *
 */

NumCell::~NumCell() {
}

/**
 * @brief	 Evaluates the cell to its numeric value
 *
 * @returns	 Cell value
 *
 */

double NumCell::evaluate() const {
	return value;
}

/**
 * @brief	  Gives the string representation of the cell, with
 * 			  precision of 3 digits after the floating point, if 
 * 			  present Any trailing zeros are not being printed
 *
 * @returns	  String representation of the number
 *
 */

std::string NumCell::toString() const {
	if (std::fabs(value - std::round(value)) < 0.001)
		return std::to_string((int)std::round(value));

	int x = std::round(1000 * value), precision = 1;

	if (x % 100 != 0) {
		++precision;
		if (x % 10 != 0)
			++precision;
	}

	std::stringstream ss;
	ss << std::fixed << std::setprecision(precision) << value;
	return ss.str();
}




