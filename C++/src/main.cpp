#include <iostream>
#include <string>

#include "other/Logger.hpp"
#include "other/OutputToFile.hpp"
#include "other/InputFromFile.hpp"
#include "core/Automaton.hpp"

using namespace std;

int main(int argc, char** argv) {
	rlib::Logger log("main",true);
	log.info_line("Starting application.");

	/*************************** Remove **************************/
	log.debug_line("Argc value=" + to_string(argc));
	for(int i = 0; i < argc; i++) {
		log.debug_line("Argv[" + to_string(i) + "] value=" + argv[i]);
	}
	/*************************** Remove **************************/

	Automaton automaton;

	if(argc == 2) {
		InputFromFile ifile(argv[1]);
		automaton.setInput(ifile.readFile());
		automaton.run();
	}

	log.info_line("Closing application.");
}
