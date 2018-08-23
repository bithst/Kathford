% find sum of all items of a list
sum([], 0).
sum([H|T], X) :-
	sum(T, Xt),
	X is H + Xt.

% find sum of even numbers of a list
sum_even([], 0).
sum_even([H|T], X) :-
	(H mod 2 =:= 0) ->
	sum_even(T, Xt),
	X is H + Xt;
	sum_even(T, Xt),
	X is Xt + 0.

% sum of square f each element of list
sum_square([], 0).
sum_square([H|T], X) :-
	Square is H * H,
	sum_square(T, Xt),
	X is Square + Xt.