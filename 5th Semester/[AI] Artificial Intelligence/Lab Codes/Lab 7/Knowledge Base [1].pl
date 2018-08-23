member('Dave').
member('Fred').

cannot(X, 'Jive'):-
	member(X),
	can(X, 'Waltz').

cannot(X, 'Waltz'):-
	member(X),
	can(X, 'Jive').

cannot(X, Y):-
	parent_cannot(X, Y).

parent_cannot('Fred', 'Waltz').

can('Dave', Y):-
	cannot('Fred', Y).