#include "TextCell.h"
#include "StringUtils.h"
#include <string>

/**
 * @brief			 Constucts a text cell from given text that
 * 					 should be enclosed by quotation mark '"'
 *
 * @param [in]	str	 Text
 *
 */

TextCell::TextCell(const std::string& str) :str(str) {
}

/**
 * @brief	Default destructor for text cell
 *
 */

TextCell::~TextCell() {
}

/**
 * @brief	 Tries to extract a number from the quoted text. If the text
 * 			 cannot be translated to a numeric value, 0 is returned
 *
 * @returns	 Extracted numeric value of cell, or 0 if failed
 *
 */

double TextCell::evaluate() const {
	double value = 0.;
	std::string content = str.substr(1, str.size() - 2);

	if (StringUtils::isNumber(content))
		value = std::stod(content);

	return value;
}

/**
 * @brief	  Returns the text value of the cell
 *
 * @returns	  Text value of the cell
 *
 */

std::string TextCell::toString() const {
	return str;
}

