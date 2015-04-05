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

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS
#include "State.hpp"
#include "../data/GraphList.hpp"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class StateFindPath: public State {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	int findLeastPath(const GraphList & graph, const int & from, const int & to) const {
		int actualNode = from;
		int result = 0;
		find();
		return result;
	}

	int void find(const GraphList & graph, const int & from, const int & to) {
		// Pokud jsem v cíli, dál nepokračuj.
		if(from == to) {
			return 0;
		}

		int value = -1;
		int returnedValue = 0;
		bool end = false;

		// Hledej dokud nejsi na konci.
		while(!end) {
			// Podívej se na všechny cesty z toho uzlu.
			auto paths = graph.get(from);
			// Pokud nejsou další cesty ukonči smyčku a vrať -1.
			if(paths.size() == 0) {
				return -1;
			}
			// Pro každou možnou cestu
			for (std::vector<int>::iterator i = paths.begin(); i != paths.end(); ++i) {
				// Pokud existuje z tohoto uzlu do cílového uzlu cesta, vrať jeho hodnotu.
				if(*i == to) {
					return graph.get(from,to);
				}
				// Pokud ne, hledej dál.
				returnedValue = find(graph,*i,to);
				// Není cesta
				if(returnedValue == -1) {
					return -1;
				}
				value += graph.get(from, *i) + returnedValue;
			}
		}
		return value;
	}

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
		if(values.size() == 3) {
			return 1;
		}

		int result = findLeastPath(graph, std::stoi(values[0]),std::stoi(values[1]));
		if(result >= 0) {
			std::cout << result << std::endl;
		} else {
			std::cout << "no path" << std::endl;
		}
		
		return 0;
	}
};

