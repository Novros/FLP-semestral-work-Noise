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
#include <queue>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS
#include "State.hpp"
#include "../data/GraphList.hpp"
#include "../data/PriorityQueue.hpp"

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
	int* stav;
	int* path;
	std::vector<int> decibels;
	int N;
	int from;
	int to;
protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:
	void init(const GraphList & graph) {
		decibels.clear();
		delete[] stav;
		delete[] path;

		int N = graph.getN();
		stav = new int[N];
		path = new int[N];
		for (int i = 0; i < N; ++i) {
			stav[i] = FRESH; 
			path[i] = -1;
		}
	}

	int findDecibelMaxValue(const GraphList & graph) {
		int max = 0;
		int temp = to;
		std::cout << std::endl;
		while(temp != from) {
			std::cout << path[temp] << "-> " << temp << " " << graph.get(path[temp],temp) << std::endl;
			if(graph.get(path[temp],temp) > max) {
				max = graph.get(path[temp],temp);
			}
			temp = path[temp];
		}
		return max;
	}

	void DFSProjdi(const GraphList & graph, int u) {
		//stav[u] = OPEN;
		std::vector<int> adjected = graph.get(u);
		for (auto i = adjected.begin(); i != adjected.end(); ++i) {
			//if (stav[*i] == FRESH)  {
				path[*i] = u;
				if(*i == to) {	
					decibels.push_back(findDecibelMaxValue(graph));
				}
				DFSProjdi(graph, *i);
			//}
		}
		//stav[u] = CLOSED;
	}

	int getLeastDecibels() {
		int min = INFINITY;
		for (std::vector<int>::iterator i = decibels.begin(); i != decibels.end(); ++i) {
			if(*i < min) {
				min = *i;
			}
		}
		return min;
	}


	int findLeastPath(const GraphList & graph, const int & from, const int & to) {
		this->from = from;
		this->to = to;
		init(graph);

		std::cout << "Find: " << from << " -> " << to << std::endl;
		graph.printGraph();

		DFSProjdi(graph,from);
		return getLeastDecibels();
	}

protected:

public:
	/*********************************************** Constructors ****************************************************/

	/************************************************** Others *******************************************************/
	int run(std::string line, GraphList & graph) {
		std::vector<std::string> values = parseString(line, " ");
		if(values.size() == 3) {
			return 1;
		}

		int result = findLeastPath(graph, std::stoi(values[0]), std::stoi(values[1]));
		if(result == 9999) {
			std::cout << "no path" << std::endl;
		} else {
			std::cout << result << std::endl;
		}		
		
		return 0;
	}
};

