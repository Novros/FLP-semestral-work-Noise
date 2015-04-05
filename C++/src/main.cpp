#include <iostream>
#include <string>

#include "other/InputFromFile.hpp"
#include "core/Automaton.hpp"

using namespace std;

int main(int argc, char** argv) {
	Automaton automaton;

	if(argc == 2) {
		InputFromFile ifile(argv[1]);
		automaton.setInput(ifile.readFile());
		automaton.run();
	}
}
