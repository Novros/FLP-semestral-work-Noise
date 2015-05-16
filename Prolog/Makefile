CXX = swipl
EXE = test

all: $(EXE)

build: $(EXE)

rebuild:
	make clean && make

rerun:
	make rebuild && make run

clean:
	rm $(EXE)

run: all
	./$(EXE) test.txt

$(EXE): main.pl
	$(CXX) -o $@ -c $< 