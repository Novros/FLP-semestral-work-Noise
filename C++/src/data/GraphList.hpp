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
#include <utility>
#include <tuple>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class GraphList {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	int N = -1;
	int** graph;
protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/
	GraphList() {
	}

	~GraphList() {
		deleteGraph();
	}

	/************************************************** Others *******************************************************/
	int getN() const {
		return N;
	}

	void put (const int & from, const int & to, const int & value) {
		graph[from-1][to-1] = value;
	}

	std::vector<int> get (const int & position) const {
		std::vector<int> vector;
		for (int i = 0; i < N; ++i)
		{
			if(graph[position-1][i] > 0) {
				vector.push_back(i+1);
			}
		}
		return vector;
	}

	int get (const int & first, const int second) const {
		return graph[first-1][second-1];
	}

	void printGraph() const {
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				std::cout << graph[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}

	void clear(const int & N) {
		if(this->N > 0) {
			deleteGraph();
		}
		this->N = N;
		createGraph();
	}

	void deleteGraph() {
		for (int i = 0; i < N; ++i) {
			delete[] graph[i];
		}
		delete[] graph;
	}

	void createGraph() {
		graph = new int*[N];
		for (int i = 0; i < N; ++i) {
			graph[i] = new int[N];
			for (int j = 0; j < N; ++j)
			{
				graph[i][j] = 0;
			}
		}
	}
};

