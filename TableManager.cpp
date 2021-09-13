#include "TableManager.h"
#include "StringUtils.h"
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <algorithm>
#include <fstream>

bool validateFileExtension(const std::string&);
bool validateFileName(const std::string&);

/**
 * @brief	Default constructor creating with no table
 * 			present and empty data file
 *
 */

TableManager::TableManager() :table(nullptr), file("") {
}

/**
 * @brief	Destructor destroying the object and taking care
 * 			of allocated dynamic memory
 *
 */

TableManager::~TableManager() {
	if (table != nullptr)
		delete table;
}

/**
 * @brief	Starts the command console to read user commands
 *
 */

void TableManager::startConsole() {
	std::cout << "Open a text file (.txt) to read: (open <file>.txt)" << std::endl;
	std::string userInput;

	while (true) {
		std::getline(std::cin, userInput);
		executeCommand(userInput);
	};
}

/**
 * @brief    Prints available user commands
 *
 */

void TableManager::help() const {
	std::cout << "open <file>                  opens <file>\n"
		<< "close                        closes currently opened file\n"
		<< "save                         saves the currently open file\n"
		<< "saveas <file>                saves the currently open file in <file>\n"
		<< "help                         prints this information\n"
		<< "print                        print the current table\n"
		<< "edit <row> <col> <value>     print the current table\n"
		<< "exit                         exists the program" << std::endl;
}

/**
 * @brief    Exits the programme
 *
 */

void TableManager::exit() {
	std::cout << "Programme terminated succesfully!" << std::endl;
	std::exit(0);
}

/**
 * @brief    Closes the current open file and clears any data read
 *
 */

void TableManager::close() {
	if (table != nullptr) {
		delete table;
		table = nullptr;
	}

	std::cout << "Succesfully closed current file!" << std::endl;
	file = "";
}

/**
 * @brief    Prints the table if present
 *
 */

void TableManager::print() const {
	if (table != nullptr)
		table->print();
}

/**
 * @brief	           Opens a file to read from
 *
 * @param [in]  file   File to read
 *
 */

void TableManager::open(const std::string& file) {
	std::fstream myFile(file, std::ios::app);

	if (myFile.is_open()) {
		std::cout << "Succesfully opened file " << file << "!" << std::endl;
		myFile.close();
		readFile(file);
	}

	else
		std::cout << "Error opening the file!" << std::endl;

}

/**
 * @brief	           Read data from a given file
 *
 * @param [in]  file   File to read
 *
 */

void TableManager::readFile(const std::string& file) {
	std::ifstream myFile(file, std::ios::in);

	if (!myFile.is_open()) {
		std::cout << "Error opening the file!" << std::endl;
		return;
	}

	this->file = file;
	char delimeter = ',';
	int rows = 0, maxColumns = 0, countTokens = 0;
	std::string line;

	while (std::getline(myFile, line)) {
		++rows;
		int countTokens = std::count(line.begin(), line.end(), delimeter);
		if (countTokens > maxColumns)
			maxColumns = countTokens;
	}

	myFile.close();

	if (rows == 0) {
		table = new Table(10, 10);
		std::cout << "File empty! Generated default 10x10 empty table" << std::endl;
	}

	else {
		table = new Table(rows, maxColumns);
		populateTable(file, delimeter);
	}
}

/**
 * @brief				   Read data and populate table from file. If given row has
 * 						   more cells than another one, the second is autofilled with empty cells
 *
 * @param  [in]	  file 	   The file to read
 *
 * @param  [in]	  delim	   The delimiter used in data file
 */

void TableManager::populateTable(const std::string& file, char delim) {
	std::ifstream myFile(file, std::ios::in);
	std::string line;
	int row = 0;
	while (std::getline(myFile, line)) {
		++row;

		if (!line.empty()) {
			int col = 0;
			size_t pos = 0;
			std::string token, delimeter = std::string(1, delim);
			while ((pos = line.find(delimeter)) != std::string::npos) {
				++col;
				token = line.substr(0, pos);
				if (!token.empty()) {
					table->editCell(row, col, token, true);
				}

				line.erase(0, pos + delimeter.length());
			}
		}
	}
}

/**
 * @brief    Saves the current data in the current file
 *
 */


void TableManager::save() {
	assert(!file.empty());

	std::fstream myFile(file, std::ios::out | std::ios::trunc);

	if (myFile.is_open()) {
		myFile << *table;
		myFile.close();
		std::cout << "Table saved successfully!" << std::endl;
	}

	else
		std::cout << "Error opening the file!" << std::endl;
}

/**
 * @brief			   Writes current data to the file specified
 *
 * @param [in]  file   File to write data to
 *
 */

void TableManager::saveAs(const std::string& file) {
	std::ofstream myFile(file, std::ios::out | std::ios::trunc);

	if (myFile.is_open()) {
		myFile << *table;
		myFile.close();
		std::cout << "Table saved successfully as " << file << "!" << std::endl;
	}

	else
		std::cout << "Error opening the file!" << std::endl;
}

/**
 * @brief			Validates if the given file is .txt format and
 * 					its name is valid
 *
 * @param 	file	The file.
 *
 * @returns			True if file is valid, false if it fails.
 */

bool TableManager::validateFile(const std::string& file) {
	if (file.size() < 5) {
		std::cout << "Filename too short! (Hint: File format should be filename.txt)" << std::endl;
		return false;
	}

	std::string name = file.substr(0, file.size() - 4);
	std::string extension = file.substr(file.size() - 4, 4);
	std::string forbiddenSymbols = "/\?%*:|\"<>.";

	return validateFileExtension(extension) && validateFileName(name);
}

/**
 * @brief				Checks if file extension is '.txt'
 *
 * @param 	extension	File extension
 *
 * @returns				True if it is .txt, false otherwise
 *
 */

bool validateFileExtension(const std::string& extension) {
	bool result = true;

	if (extension != ".txt") {
		std::cout << "Invalid file extension! (Hint: File should be .txt)" << std::endl;
		result = false;
	}

	return result;
}

/**
 * @brief			Validates the file name.Name should not contain  any
 * 					forbidden OS characters specified by the Windows OS
 *
 * @param 	name	File name
 *
 * @returns			True if it is valid, false otherwise
 *
 */

bool validateFileName(const std::string& name) {
	assert(!name.empty() && "Name should not be empty string");

	bool result = true;

	std::string badChars = "/\?%*:|\"<>.";
	std::size_t badChar = name.find_first_of(badChars);

	if (badChar != std::string::npos) {
		std::cout << "Invalid file name! (Hint: Check forbidden filename characters in Windows OS)" << std::endl;
		result = false;
	}

	return result;
}

/**
 * @brief	             Edit given cell with the value specified
 *
 * @param [in]  args	 User console input specifying the cell and the new value
 *
 */

void TableManager::edit(const std::string& args) {
	int firstDelim = -1, secondDelim = -1;
	char delimeter = ' ';

	for (size_t i = 0; i < args.size() - 1; ++i) {
		if (args.at(i) == delimeter)
			if (firstDelim == -1)
				firstDelim = i;
			else {
				secondDelim = i;
				break;
			}
	}

	if (secondDelim != -1) {
		std::string stringRow = args.substr(0, firstDelim), stringCol = args.substr(firstDelim + 1, secondDelim - firstDelim - 1);
		std::string  value = args.substr(secondDelim + 1);

		if (StringUtils::isInteger(stringRow) && StringUtils::isInteger(stringCol)) {
			int row = std::stoi(stringRow), col = std::stoi(stringCol);

			table->editCell(row, col, value);
			return;
		}
	}

	std::cout << "Invalid command! (Hint: Command should be: edit <row> <col> <value>)" << std::endl;
}

/**
 * @brief	              Executes a console-typed user command. If the given input
 * 						  does not match any command, proper error message is printed
 *
 * @param [in]  command	  User console input
 *
 */

void TableManager::executeCommand(std::string& command) {
	StringUtils::trim(command);

	if (command.size() < 4) {
		std::cout << "Command too short" << std::endl;
		return;
	}

	if (file.empty()) {
		if (command.size() >= 10 && command.substr(0, 5) == "open ") {
			std::string file = command.substr(5);
			if (validateFile(file)) {
				open(file);
			}
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}

	else if (functions.find(command) != functions.end())
		functions.at(command)();


	else if (command.substr(0, 7) == "saveas ") {
		std::string file = command.substr(7);
		if (validateFile(file)) {
			saveAs(file);
		}
	}

	else if (command.substr(0, 5) == "edit ") {
		std::string commandArguments = command.substr(5);
		edit(commandArguments);
	}

	else
		std::cout << "Invalid command! (Hint: type help to see available commands)" << std::endl;
};

