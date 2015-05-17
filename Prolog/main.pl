% maxHelp(+A, +B, -X)
% Returns in X maximum from two values.
maxHelp(A, B, X) :- A > B, X is A.
maxHelp(A, B, X) :- A < B, X is B.

max([Element], Element).
max([Element | Rest], X) :- max(Rest, Y), maxHelp(Element, Y, X).

min([Element], Element).
min([Element | Rest], X) :- max(Rest, Y), maxHelp(Y, Element, X).

% reverse(+List,-List2)
% Reverse list.
reverse(List1, List2) :- reverse(List1, [], List2).
reverse([], All, All).
reverse([X | List], List2, Temp) :- reverse(List, [X | List2], Temp).

% path(+End, +End, +ForwadPath, -BackwardPath).
% I am in end of path.
path(End, End, ForwadPath, [End | ForwadPath]).

% Looking for next node to end. In backtracking filling path, which we are looking for. (BackwardPath)
path(Start, End, ForwadPath, BackwardPath ) :-
	edge(Start, Node, _), % For every neighb.
	not(member(Node, ForwadPath)), % I was not in this node.
	path(Node, End, [Start | ForwadPath], BackwardPath). % Look again for end.

dfs(Start, End, Path) :- path(Start, End, [], Path1), reverse(Path1, Path).

% valuePath(+Path, -ValuePath).
% Return list of decibels in each edge.
valuePath([Start, End ], [X] ) :- edge(Start, End, X).
valuePath([Start, Node | Path], [ X | ValuePath]) :- valuePath([Node | Path], ValuePath), edge(Start, Node, X).

allMinDFS(Start, End, Max) :- dfs(Start, End, Path), valuePath(Path, ValuePath), max(ValuePath, Max).

minDFS(Start, End, Min) :- setof(X, allMinDFS(Start, End, X), [Min | List]).

readFile(Stream, []) :- at_end_of_stream(Stream).
readFile(Stream, [X | List]) :- not(at_end_of_stream(Stream)), get_char(Stream, X), readFile(Stream,List).

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
parseInput([X | List], List2, [Number | Temp]) :- char_type(X,digit), atom_number(X,Number), parseInput(List, List2, Temp).
parseInput([X | List], List2, Temp) :- parseInput(List, List2, Temp).

main :- open("test.txt", read, Stream),
	readFile(Stream,Lines),
    close(Stream),
    parseInput(Lines,X),
    runCases(X,1).

displayCase(NumberCase) :- write('Case #'), write(NumberCase), nl.

createGraph(Lines, 0, Lines).
createGraph([NodeA, NodeB, Value | Lines], Index, X) :- Index1 is Index-1, createGraph(Lines, Index1, X), asserta(edge(NodeB,NodeA,Value)), asserta(edge(NodeA,NodeB,Value)).

runTests(Lines, 0, Lines).
runTests([Start, End | Lines], Index, X) :- minDFS(Start,End,Min),write(Min),nl,Index1 is Index-1, runTests(Lines,Index1, X).

runCase(Lines,Edges,Tests,Y) :- createGraph(Lines,Edges,X),runTests(X,Tests,Y).

runCases([Size,Edges,Tests], NumberOfCase) :- Size =:= 0, Edges =:= 0, Tests =:= 0.
runCases([Size,Edges,Tests | List], NumberOfCase) :- Size > 0, displayCase(NumberOfCase),runCase(List,Edges,Tests,X), nl, NumberOfCase1 is NumberOfCase + 1, runCases(X,NumberOfCase1).