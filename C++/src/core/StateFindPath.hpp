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
// CONSTANTS
 #define OPEN 1
 #define CLOSED 2
 #define FRESH 0
 #define INFINITY 9999

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
	int N;
	int from;
	int to;
	int minDecibels = INFINITY;
protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:
	void findLeastPath(const GraphList & graph, const int & from, const int & to) {
		// Ulož si hodnoty
		this->from = from;
		this->to = to;
		this->N = graph.getN();
		minDecibels = INFINITY;

		DFSProjdi(graph, from, 0, 0);
	}

	void DFSProjdi(const GraphList & graph, const int & u, const int & maxDecibels, const int & edgeCount) {
		// Pokdu jsi v maximální hloubce, ukonči (Max hloubka = počet hran)
		if(edgeCount > graph.getE()) {
			return;
		}
		// Získej všechny sousedy
		std::vector<int> adjected = graph.get(u);
		// Pro každého souseda proveď
		for (auto i = adjected.begin(); i != adjected.end(); ++i) {
			// Pokud je to cíl, ulož minimální hodnotu pro tuto cestu a vrať se
			if(*i == to) {
				int temp = (maxDecibels < graph.get(u, *i)) ? graph.get(u,*i) : maxDecibels;
				if(minDecibels > temp) {
					minDecibels = temp;
				}
				return;
			}
			// Jdi do dalšího uzlu
			if(maxDecibels < graph.get(u,*i)) {
				DFSProjdi(graph, *i, graph.get(u, *i), edgeCount+1);
			} else {
				DFSProjdi(graph, *i, maxDecibels, edgeCount+1);
			}
		}
	}

protected:

public:
	/*********************************************** Constructors ****************************************************/
	~StateFindPath() {
	}

	/************************************************** Others *******************************************************/
	int run(std::string line, GraphList & graph) {
		std::vector<std::string> values = parseString(line, " ");
		if(values.size() == 3) {
			return 1;
		}

		findLeastPath(graph, std::stoi(values[0]), std::stoi(values[1]));
		if(minDecibels == 9999) {
			std::cout << "no path" << std::endl;
		} else {
			std::cout << minDecibels << std::endl;
		}		
		
		return 0;
	}
};

