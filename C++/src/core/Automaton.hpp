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
#include <iostream>
#include <vector>
#include <string>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS
#include "../other/Logger.hpp"
#include "State.hpp"
#include "StateCreateGraph.hpp"

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
	// TODO to smart pointers
	rlib::Logger* log;
	//std::stringstream* inputStream;
	State* state;
	std::vector<std::string> lines;

protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/
	Automaton() {
		// Set logger
		log = new rlib::Logger("Automaton",true);
		log->info_line("Creating automaton...");

		// Set input stream
		/*inputStream = new std::stringstream();		
		std::cin.rdbuf(inputStream->rdbuf());
		*inputStream << buf;*/

		// Set state
		state = new StateCreateGraph();

	}

	~Automaton() {
		delete log;
	}

	/************************************************** Others *******************************************************/
	void run() {

	}

	/************************************************* Getters *******************************************************/

	/************************************************* Setters *******************************************************/
	void setInput(std::string input) {
		log->debug_line("Setting input string in automaton...");
		//log->debug_line(input);

		size_t pos = 0;
		std::string token;
		std::string delimiter = "\n";
		while((pos = input.find(delimiter)) != std::string::npos) {
			token = input.substr(0, pos);
			lines.push_back(token);
			input.erase(0, pos + delimiter.length());
		}

	}

};

