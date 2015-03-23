# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXX = g++
CXXFLAGS = -Wall -c -std=c++11 -ggdb -O0
LDFLAGS = 
EXE = test
DEBUGGER = valgrind

OBJECTS = objects/main.o objects/State.o objects/Automaton.o
all: $(EXE)

build: $(EXE)

run: all
	./$(EXE) test.txt

debug: all
	$(DEBUGGER) ./$(EXE) test.txt

debug-memory: all
	$(DEBUGGER) --leak-check=full --show-leak-kinds=all ./$(EXE) test.txt

rebuild:
	make clean && make

$(EXE): $(OBJECTS)
	mkdir -p objects
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)

objects/main.o: src/main.cpp
	mkdir -p objects
	$(CXX) $(CXXFLAGS) -c $< -o $@

objects/Automaton.o: src/core/Automaton.cpp src/core/Automaton.hpp
	mkdir -p objects
	$(CXX) $(CXXFLAGS) -c $< -o $@

objects/State.o: src/core/State.cpp src/core/State.hpp
	mkdir -p objects
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -r objects && rm $(EXE)
