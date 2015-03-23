#include "Automaton.hpp"

Automaton::Automaton() {
	// Set //logger
	log = new rlib::Logger("Automaton",true);
	//log->info_line("Creating automaton...");

	// Set state
	state = new StateCreateGraph();

	newGraph();
}

Automaton::~Automaton() {
	delete log;
}

void Automaton::run() {
	bool end = false;
	int previousCount = 3;
	for(auto &line : lines) {
		
		// Check count of numbers
		std::vector<std::string> numbers = parseString(line," ");
		int count = numbers.size();
		int transition = count - previousCount;
		previousCount = count;
		//log->debug_line("Count is " + std::to_string(count));
		//log->debug_line("Previous count is " + std::to_string(previousCount));

		if((count == 3) && (stoi(numbers[0]) == stoi(numbers[2])) && (stoi(numbers[0]) == stoi(numbers[1]))) {
			transition = 2;
		}

		// Check if not new state
		switch(transition) {
			case 0:
				break;
			case 1:
				//log->info_line("Changing state to 1.");
				delete state;
				state = new StateCreateGraph();
				newGraph();
				break;
			case -1:
				//log->info_line("Changing state to 2.");
				delete state;
				state = new StateFindPath();
				break;
			case 2:
				//log->info_line("Ending, because of input has 0 0 0.");
				end = true;
				break;
			default:
				log->error_line("Bad transition number. value=" + std::to_string(transition));
				end = true;
				break;
		}
	
		// if zero, end
		if(end) {
			break;
		}

		//log->debug_line("State has line: " + line);
		// Text line to state, send graph table
		transition = state->run(line, graph);
	}
}