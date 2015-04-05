#include "Automaton.hpp"

Automaton::Automaton() {
}

Automaton::~Automaton() {
	delete state;
}

void Automaton::run() {
	int line = 0;
	while(true) {
		// Read first line state
		std::vector<std::string> numbers = parseString(lines[line]," ");
		int C = stoi(numbers[0]), S = stoi(numbers[1]), Q = stoi(numbers[2]);
		if( C == 0 && S == 0 && Q == 0) {
			break;
		}
		line++;

		// Create state
		delete state;
		state = new StateCreateGraph();
		newGraph(C);
		graph.setE(S);
		for(int i = 0; i < S; i++, line++) {
			state->run(lines[line], graph);
		}

		// Find state
		delete state;
		state = new StateFindPath();
		for(int i = 0; i < Q; i++, line++) {
			state->run(lines[line], graph);
		}
	}
}