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

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
namespace rlib {
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class OutputToFile {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	std::string fileName;
	std::ofstream fileStream;

protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/
	// TODO Check exceptions.
	// TODO Binary writting and so on.
	OutputToFile(const std::string & fileName, const bool append = false, const bool binary = false) {
		this->fileName = fileName;
		fileStream.open(fileName);
	}

	~OutputToFile() {
		fileStream.close();
	}

	/************************************************* Getters *******************************************************/
	std::ostream & getStream() {
		return fileStream;
	}

	/************************************************** Others *******************************************************/
	// TODO check states
	template <class T>
	void write(const T & text) {
		fileStream << text;
	}

	template <class T>
	void writeLine(const T & text) {
		fileStream << text << std::endl;
	}

	/************************************************ Operators ******************************************************/
	template <class T>
	std::ostream& operator << (const T & text) {
		fileStream << text;
		return fileStream;
	}
};

}