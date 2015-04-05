#include "Automaton.hpp"

Automaton::Automaton() {
	// Set logger
	log = new rlib::Logger("Automaton",true);
	log->info_line("Creating automaton...");

	// Set input stream
	/*inputStream = new std::stringstream();		
	std::cin.rdbuf(inputStream->rdbuf());
	*inputStream << buf;*/

	// Set state
	state = new StateCreateGraph();

	newGraph();
}

Automaton::~Automaton() {
	delete log;
}

void Automaton::run() {
	int transition;
	bool end = false;
	for(auto &line : lines) {
		log->debug_line("State has line: " + line);
		// Text line to state, send graph table
		transition = state->run(line, graph);
		
		while(transition != 0) {
			// Check if not new state
			switch(transition) {
				case 0:
					break;
				case 1:
					log->info_line("Changing state to 1.");
					delete state;
					state = new StateCreateGraph();
					newGraph();
					log->debug_line("Resending line: " + line);
					transition = state->run(line,graph);
					break;
				case 2:
					log->info_line("Changing state to 2.");
					delete state;
					state = new StateFindPath();
					log->debug_line("Resending line: " + line);
					transition = state->run(line,graph);
					break;
				case 3:
					log->info_line("Ending, because of input has 0 0 0.");
					end = true;
					transition = 0;
					break;
				default:
					log->error_line("Bad transition number. value=" + std::to_string(transition));
					end = true;
					break;
			}
		}
		// if zero, end
		if(end) {
			break;
		}
	}
}