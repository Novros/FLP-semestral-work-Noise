edge(1,2,50).
edge(2,1,50).
edge(1,3,60).
edge(3,1,60).
edge(2,4,120).
edge(4,2,120).
edge(2,5,90).
edge(5,2,90).
edge(3,6,50).
edge(6,3,50).
edge(4,6,80).
edge(6,4,80).
edge(4,7,70).
edge(7,4,70).
edge(5,7,40).
edge(7,5,40).
edge(6,7,140).
edge(7,6,140).

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