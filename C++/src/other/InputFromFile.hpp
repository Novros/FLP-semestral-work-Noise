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
#include <fstream>
#include <string>
#include <sstream>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class InputFromFile {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	std::ifstream inputStream;
protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/
	InputFromFile(std::string fileName) {
		inputStream.open(fileName);
	}

	~InputFromFile() {
		inputStream.close();
	}

	/************************************************* Getters *******************************************************/
	// TODO to smart pointers
	std::streambuf* getStream() {
		return inputStream.rdbuf();
	}

	/************************************************** Others *******************************************************/

	std::string readLine() {
		std::string line;
		if (inputStream.is_open()) {
			getline (inputStream, line);
		}
		return line;
	}

	std::string readFile() {
		std::stringstream stream;
		stream << inputStream.rdbuf();
		std::string file = stream.str();
		return file;
	}

};

