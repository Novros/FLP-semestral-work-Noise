%%%%///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
%%%% Main file o this solution in Prolog.
%%%%
%%%% author  Rostislav Novak <rostislav.novak92@gmail.com>
%%%% version 1.0
%%%%
%%%% This program is free software% you can redistribute it and/or
%%%% modify it under the terms of the GNU General Public License as
%%%% published by the Free Software Foundation; either version 2 of
%%%% the License, or (at your option) any later version.
%%%%
%%%% This program is distributed in the hope that it will be useful, but
%%%% WITHOUT ANY WARRANTY% without even the implied warranty of
%%%% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
%%%% General Public License for more details at
%%%% http://www.gnu.org/copyleft/gpl.html
%%%%///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
%%%% Main program
%%%%///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
%%%%------------------------------------------------ List procedures --------------------------------------------------

% Returns greater from two numbers.
% maxHelp(+A, +B, -Grater)
greater(A, B, X) :- A > B, X is A.
greater(A, B, X) :- A < B, X is B.

% Returns maximum from list.
% max(+List, -Max).
max([Element], Element).
max([Element | Rest], X) :- max(Rest, Y), greater(Element, Y, X).

% Returns minimum from list.
% min(+List, -Min).
min([Element], Element).
min([Element | Rest], X) :- max(Rest, Y), greater(Y, Element, X).

% Reverse list.
% reverse(+List,-List2)
reverse(List1, List2) :- reverse(List1, [], List2).
reverse([], All, All).
reverse([X | List], List2, Temp) :- reverse(List, [X | List2], Temp).

%%%%------------------------------------------------ DFS procedures --------------------------------------------------
% Return list of decibels for each edge.
% valuePath(+Path, -ValuePath).
valuePath([Start, End ], [X] ) :- edge(Start, End, X).
valuePath([Start, Node | Path], [ X | ValuePath]) :- valuePath([Node | Path], ValuePath), edge(Start, Node, X).

% Look for path in graph and returns path from end to start.
% path(+Start, +End, +[], -BackwardPath).
path(End, End, ForwadPath, [End | ForwadPath]).
path(Start, End, ForwadPath, BackwardPath ) :- % Looking for next node to end. In backtracking filling path, which we are looking for. (BackwardPath)
	edge(Start, Node, _), % For every neighb.
	not(member(Node, ForwadPath)), % I was not in this node.
	path(Node, End, [Start | ForwadPath], BackwardPath). % Look again for end.

% Returns all paths from start to end.
% dfs(+Start, +End, -Path)
dfs(Start, End, Path) :- path(Start, End, [], Path1), reverse(Path1, Path).

% Returns maximum decibels from list of decibels for each edge.
% allMinDFS(+Start, +End, -Max)
allMinDFS(Start, End, Max) :- dfs(Start, End, Path), valuePath(Path, ValuePath), max(ValuePath, Max).

% Returns minimum tolerance of decibels from all paths from start to end.
% minDFS(+Start, +End, -Min)
minDFS(Start, End, Min) :- setof(X, allMinDFS(Start, End, X), [Min | List]).

%%%%------------------------------------------------ File procedures --------------------------------------------------
% Read whole file from stream. List will be filled with chars.
% readFile(+Stream, -FileInList)
readFile(Stream, []) :- at_end_of_stream(Stream).
readFile(Stream, [X | List]) :- not(at_end_of_stream(Stream)), get_char(Stream, X), readFile(Stream,List).

%%%%------------------------------------------------ Parse procedures --------------------------------------------------
% Parse input from file. Remove white spaces, end of line and so on. Converts numbers from char to number.
% parseInput(+List, -ParsedList)
parseInput(List1, List2) :- parseInput(List1, [], List2).
parseInput([], All, All).
parseInput([X, Y, Z | List], List2, [Number | Temp]) :-
	char_type(X,digit), char_type(Y,digit), char_type(Z,digit),
	atom_number(X,HundredNumber), atom_number(Y,TensNumber), atom_number(Z, Units),
	Hundreds is HundredNumber * 100, Tens is TensNumber * 10, Number is Hundreds + Tens + Units,
	parseInput(List, List2, Temp).
parseInput([X, Y | List], List2, [Number | Temp]) :-
	char_type(X,digit), char_type(Y,digit),
	atom_number(X,TensNumber), atom_number(Y,Units),
	Tens is TensNumber * 10, Number is Tens + Units,
	parseInput(List, List2, Temp).
parseInput([X | List], List2, [Number | Temp]) :-
	char_type(X,digit),
	atom_number(X,Number),
	parseInput(List, List2, Temp).
parseInput([X | List], List2, Temp) :- parseInput(List, List2, Temp).

%%%%------------------------------------------------ Case procedures --------------------------------------------------
% Write to output Case # and number of case.
% displayCase(+NumberCase)
displayCase(NumberCase) :- write('Case #'), write(NumberCase), nl.

% Creates graph from list.
% createGraph(+Lines, +NumberOfEdges, -LinesWithouReadLines)
createGraph(Lines, 0, Lines).
createGraph([NodeA, NodeB, Value | Lines], Index, X) :-
	Index1 is Index-1,
	createGraph(Lines, Index1, X),
	asserta(edge(NodeB,NodeA,Value)),
	asserta(edge(NodeA,NodeB,Value)).

% Remove graph from database gived in list.
% removeGraph(+Lines, +NumberOfEdges, -LinesWithouReadLines)
removeGraph(Lines, 0, Lines).
removeGraph([NodeA, NodeB, Value | Lines], Index, X) :-
	Index1 is Index-1,
	retract(edge(NodeB,NodeA,Value)),
	retract(edge(NodeA,NodeB,Value)),
	removeGraph(Lines, Index1, X).

% Run test from list.
% runTests(+Lines, +NumberOfTests, -LinesWithouReadLines).
runTests(Lines, 0, Lines).
runTests([Start, End | Lines], Index, X) :- minDFS(Start,End,Min),write(Min),nl,Index1 is Index-1, runTests(Lines,Index1, X).

% Run case for gived lines.
% runCase(+Lines, +NumberOfEdges, +NumberOfTests, -LinesWithouReadLines)
runCase(Lines,Edges,Tests,Y) :- createGraph(Lines,Edges,X), runTests(X,Tests,Y). removeGraph(Lines,Edges,Z).

% Run all cases in list.
% runCases(+List, +NumberOfCase)
runCases([Size,Edges,Tests], NumberOfCase) :- Size =:= 0, Edges =:= 0, Tests =:= 0.
runCases([Size,Edges,Tests | List], NumberOfCase) :-
	Size > 0,
	displayCase(NumberOfCase),
	runCase(List,Edges,Tests,X),
	nl,
	NumberOfCase1 is NumberOfCase + 1,
	runCases(X,NumberOfCase1).

%%%%-------------------------------------------------------- Main -----------------------------------------------------
% Main procedure for run program.
main :- open("test.txt", read, Stream),
	readFile(Stream,Lines),
    close(Stream),
    parseInput(Lines,X),
    runCases(X,1).