#include <iostream>
#include "GraphList.hpp"
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	GraphList list;
	list.put(1,7,3);
	list.put(2,4,5);
	list.put(2,3,25);
	// Nepřidá se tam
	list.put(2,8,25);
	list.put(2,1,25);
	list.put(5,2,20);
	list.put(3,2,10);

	list.printGraph();

	std::vector<int> vec = list.get(2);
	cout << "Cesty pro 2." << endl;
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
	}

	cout << "Hodnota na  2,4" << endl;
	cout << list.get(2,4) << endl;

	list.clear();

	list.printGraph();

	return 0;
}