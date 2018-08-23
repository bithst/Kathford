% Not working
horse(bluebird).
horse(X):-
	mammal(X).
parent(bluebird, charlie).
offspring(charlie, bluebird).
mammal(X):-parent(X, Y), offspring(Y, X).

% Second premise
roman(X):-
	pompeian(X).
loyal_to(X, Y):-
	roman(X),
	not(try_to_assassinate(X, Y)).
hate(X, Y):-
	roman(X),
	not(loyal_to(X, Y)).
try_to_assassinate("marcus", "caesar").
pompeian("marcus").