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
		int N = graph.getN();
		int distance[N];
		int path[N];
		std::queue<int> q;
		for(int i = 0; i < N; i++) {

			// Inicializace
			q.push(i);
			distance[i] = 0;
			for(int j = 0; j < N; j++) {
				if( j != i ) {
					q.push(j);
					distance[j] = 9999;
				}
				path[j] = 0;
			}

			//Dijsktra
			int v, w;
			while(!q.empty()) {
				v = q.front();
				q.pop();
				for(int j = 0; j < N; j++) {
					if(graph.get(v,j) != -1) {
						w = j;
						if( (distance[v] + graph.get(v,j)) < distance[w]) {
							distance[w] = distance[v] + graph.get(v,j);
							path[w] = v;
						}
					}
				}
			}
		}

		return distance[to];
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

