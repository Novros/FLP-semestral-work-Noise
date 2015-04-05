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
#include <string>
#include <vector>
 
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS
#include "State.hpp"
#include "../data/GraphList.hpp"
#include "../other/ParseString.hpp"


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class StateCreateGraph : public State {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:

protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/

	/************************************************** Others *******************************************************/
	int run(std::string line, GraphList & graph) {
		std::vector<std::string> values = parseString(line, " ");
		
		if(values.size() == 2) {
			return 2;
		} else if ( (std::stoi(values[0]) == 0) && (std::stoi(values[0]) == std::stoi(values[1])) && (std::stoi(values[0]) == std::stoi(values[1])) ) {
			return 3;
		}

		graph.put(std::stoi(values[0]),std::stoi(values[1]),std::stoi(values[2]));
		graph.put(std::stoi(values[1]),std::stoi(values[0]),std::stoi(values[2]));
		return 0;
	}
};

