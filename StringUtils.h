#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

/**
 * @namespace	StringUtils
 *
 * @brief		Contains some useful methods for string and char manipulation
 * 				and data type asserting
 */

namespace StringUtils
{
	bool isDigit(char);
	bool isMathOperator(char);
	bool isSign(char);
	void trim(std::string&);
	bool isNumber(const std::string&);
	bool isInteger(const std::string&);
	bool isFormula(const std::string&);
	bool isCellReference(const std::string&);
	bool isQuotedText(const std::string&);
};

#endif

