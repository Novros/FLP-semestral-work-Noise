/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * @file
 * @author  Rostislav Novak <rostislav.novak92@gmail.com>
 * @version 1.0
 *
 * @section LICENSE* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
**/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// STL HEADERS
#include <vector>
#include <string>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS
#include "../other/Logger.hpp"
#include "State.hpp"
#include "StateCreateGraph.hpp"
#include "StateFindPath.hpp"
#include "../data/GraphList.hpp"
#include "../other/ParseString.hpp"
#include "../other/OutputToFile.hpp"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class Automaton {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	int caseNumber = 1;
	rlib::Logger* log;
	State* state;
	std::vector<std::string> lines;
	GraphList graph;
protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/
	Automaton();
	~Automaton();

	/************************************************** Others *******************************************************/
	void run();

	void newGraph(const int & N) {
		std::cout << "\nCase #" << caseNumber << std::endl;
		graph.clear(N);
		caseNumber++;
	}

	/************************************************* Getters *******************************************************/

	/************************************************* Setters *******************************************************/
	void setInput(std::string input) {
		//log->debug_line("Setting input string in automaton...");
		lines = parseString(input, "\n");
	}

};

