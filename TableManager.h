#ifndef TABLE_MANAGER_H
#define TABLE_MANAGER_H

#include "StringUtils.h"
#include "Table.h"
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <cassert>

/**
 * @class	TableManager
 *
 * @brief	Class responsible for running and managing the table,
 * 			handling user commands and data files
 *
 */

class TableManager
{
public:
	TableManager();
	~TableManager();

	void startConsole();

private:
	/**
	 * Table being currently operated
	 */
	Table* table;

	/**
	 * The file the system is currently working with, if present
	 */
	std::string file;

	/**
	 * Map of user-available plain no-args commands and their string representation
	 */

	const std::map<std::string, std::function<void(void)>>  functions = {
		{ "save", std::bind(&TableManager::save, this)},
		{ "print", std::bind(&TableManager::print, this)},
		{ "help", std::bind(&TableManager::help, this)},
		{ "close", std::bind(&TableManager::close, this)},
		{ "exit", std::bind(&TableManager::exit, this)}
	};

	void help() const;
	void exit();
	void close();
	void print() const;
	void open(const std::string&);
	void readFile(const std::string&);
	void populateTable(const std::string&, char);
	void save();
	void saveAs(const std::string&);
	bool validateFile(const std::string&);
	void edit(const std::string&);
	void executeCommand(std::string&);

};

#endif