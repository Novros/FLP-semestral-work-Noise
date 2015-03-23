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
	int N = 0;
	std::vector< std::pair< int,std::vector< std::pair< int, int > > > > graph;
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

	/************************************************** Others *******************************************************/
	int getN() const {
		return N;
	}

	void put (const int & from, const int & to, const int & value) {
		if(to > N) {
			N = to;
		}
		bool added = false;
		for (auto i = graph.begin(); i != graph.end(); ++i) {
			if(std::get<0>(*i) < from) {
			} else if(std::get<0>(*i) == from) {
				for (auto j = std::get<1>(*i).begin(); j != std::get<1>(*i).end(); ++j) {
					if(std::get<0>(*j) < to) {
					// Problém když je to rovno.
					} else {
						std::get<1>(*i).insert(j, std::make_pair(to, value));
						added = true;
						break;
					}
				}
				if(!added) {
					std::get<1>(*i).insert(std::get<1>(*i).end(), std::make_pair(to, value));
					added = true;	
				}
			} else {
				auto pair = std::make_pair(to,value);
				std::vector<std::pair<int,int> > vector;
				vector.push_back(pair);
				graph.insert(i, std::make_pair(from,vector));
				added = true;
			}
			if(added) {
				break;
			}
		}

		if(!added) {
			auto pair = std::make_pair(to,value);
			std::vector<std::pair<int,int> > vector;
			vector.push_back(pair);
			graph.insert(graph.end(), std::make_pair(from,vector));
		}
	}

	std::vector<int> get (const int & position) const {
		std::vector<int> vector;
		for (auto i = graph.begin(); i != graph.end(); ++i) {
			if(std::get<0>(*i) == position) {
				for (auto j = std::get<1>(*i).begin(); j != std::get<1>(*i).end(); ++j){
					vector.push_back(std::get<0>(*j));
				}
				return vector;
			}
		}
		return vector;
	}

	int get (const int & first, const int second) const {
		for (auto i = graph.begin(); i != graph.end(); ++i) {
			if(std::get<0>(*i) == first) {
				for (auto j = std::get<1>(*i).begin(); j != std::get<1>(*i).end(); ++j){
					if(std::get<0>(*j) == second) {
						return std::get<1>(*j);
					}
				}
			}
		}
		return 0;
	}

	void printGraph() {
		for(auto i = graph.begin(); i != graph.end(); ++i) {
			std::cout << std::get<0>(*i) << ": ";
			for(auto j = std::get<1>(*i).begin(); j != std::get<1>(*i).end(); ++j) {
				std::cout << "(" << std::get<0>(*j) << "," << std::get<1>(*j) << ") ";
			}
			std::cout << std::endl;
		}
	}

	void clear() {
		graph.clear();
	}
};

