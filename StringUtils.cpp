#include "StringUtils.h"
#include <regex>

using namespace std::regex_constants;

/**
 * @brief			 Check if a character is a sign, either '+' or '-'
 *
 * @param [in]	ch	 Character to check
 *
 * @returns			 True if the given character is a sign, false otherwise
 *
 */

bool StringUtils::isSign(char ch)
{
	return ch == '+' || ch == '-';
}

/**
 * @brief			 Check if character is a digit
 *
 * @param [in]	ch	 Character to check
 *
 * @returns			 True if the given character is a digit, false otherwise
 *
 */


bool StringUtils::isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

/**
 * @brief			 Check if character is arithemtic operator (+, - , *, / and ^)
 *
 * @param [in]	ch	 Character to check
 *
 * @returns			 True if the given character is operator, false otherwise
 *
 */

bool StringUtils::isMathOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

/**
 * @brief				 Trims in-place the given string removing all leading and trailing whitespace characters.
 * 						 Whitespace characters are denoted by isspace() standart function and include
 *						 space, form feed, line feed, carriage return, horizontal tab and vertical tab
 *
 * @param [in,out]	str	 String to be trimmed
 *
 */

void StringUtils::trim(std::string& str) {
	if (str.empty())
		return;

	std::string spaceChars = " \t\f\v\n\r";

	std::size_t pos1 = str.find_first_not_of(spaceChars);
	std::size_t pos2 = str.std::string::find_last_not_of(spaceChars);

	if (pos1 != std::string::npos && pos2 != std::string::npos)
		str = str.substr(pos1, pos2 - pos1 + 1);
}

/**
 * @brief			 Check if string represents an integer. Note that '+' or '-'
 * 					 sign are allowed in the beginning of the integer
 *
 * @param [in]	str	 String to check
 *
 * @returns			 True if the given string represents an integer
 *
 */

bool StringUtils::isInteger(const std::string& str) {
	const std::regex regexInteger("(\\+|-)?[0-9]+", ECMAScript);
	return std::regex_match(str, regexInteger);
}

/**
 * @brief			 Check if string represents a number. Note that '+' or '-'
 * 					 sign are allowed in the beginning of the integer along with
 * 					 floating point in the middle of the number
 *
 * @param [in]	str	 String to check
 *
 * @returns			 True if the given string represents a number, else otherwise
 *
 */

bool StringUtils::isNumber(const std::string& str) {
	const std::regex regexNumber("(\\+|-)?[0-9]+[.]?[0-9]*", ECMAScript);
	return std::regex_match(str, regexNumber);
}

/**
 * @brief			 Check if string represents a cell reference of type
 * 					 'R<row>C<col>'
 *
 * @param [in]	str	 String to check
 *
 * @returns			 True if the given string represents a reference, else otherwise
 *
 */

bool StringUtils::isCellReference(const std::string& str) {
	const std::regex regexCellReference("R[1-9][0-9]*C[1-9][0-9]*", ECMAScript);
	return std::regex_match(str, regexCellReference);
}

/**
 * @brief			 Check if string represents a table formula. Should begin with '=' and
 * 					 contains only cell references, numbers and mathematical operators
 *
 * @param [in]	str	 String to check
 *
 * @returns			 True if the given string represents a formula, else otherwise
 *
 */

bool StringUtils::isFormula(const std::string& str) {

	if (str.size() < 2 || str.front() != '=' || !isDigit(str.back()))
		return false;

	int pos = 1;

	for (int i = 1; i < str.size(); ++i) {

		char ch = str.at(i);

		if (isMathOperator(ch) || i == str.size() - 1) {
			int includeLastSymbol = (i == str.size() - 1) ? 1 : 0;
			std::string temp = str.substr(pos, i - pos + includeLastSymbol);

			if (temp.empty() || isSign(temp.front()) || !(isNumber(temp) || isCellReference(temp)))
				return false;

			pos = i + 1;
		}
	}

	return true;
}

/**
 * @brief			 Check if string represents a quoted text ""
 *
 * @param [in]	str	 String to check
 *
 * @returns			 True if the given string represents a quoted text,
 * 					 else otherwise
 *
 */

bool StringUtils::isQuotedText(const std::string& str) {
	return str.size() > 1 && str.front() == '"' && str.back() == '"';
}
