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
#include <vector>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class PriorityQueue {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	std::vector<int> vec;
protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	void push(const int & i) {
		vec.push_back(i);
	}

	int pop(int* distance) {
		int num = *vec.begin();
		std::vector<int>::iterator remove = vec.begin();
		for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
		{
			if(distance[*i] < distance[num]) {
				num = *i;
				remove = i;
			}
		}

		vec.erase(remove);

		return num;
	}

	bool empty() const {
		return vec.empty();
	}

	/*********************************************** Constructors ****************************************************/

	/************************************************** Others *******************************************************/

};

