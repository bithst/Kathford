% born(mary, kathmandu) = born(mary, X).

/*
?- 8 is 6 + 2.
true.

?- 12 is 6 * 2.
true.


?- 12 is 6*2.
true.

?- 4 is 6-2.
true.

?- -2 is 6-8.
true.

?- 3 is 6/2.
true.

?- 3 is 7/2.
false.

?- 1 is mod(7,2).
true.

?- X is 6 + 2.
X = 8.

?- x is 6*2.
false.

?- R is mod(7,2).
R = 1.

?- born(mary, kathmandu) = born(mary, X).
X = kathmandu.

?- 8 is 6+2.
true.

?- 12 is 6*2.
true.

?- 4 is 6-2.
true.

?- -2 is 6-8.
true.

?- 3 is 6/2.
true.

?- 3 is 7/2.
false.

?- 1 is mod(7,2).
true.

?- X is 6 + 2.
X = 8.

?- x is 6*2.
false.

?- R is mod(7,2).
R = 1.

?- 2<4.
true.

?- halt.

?- 2 < 4.
true.

?- 2 =< 4.
true.

?- 4 =< 4.
true.

?- 4 =:= 4.
true.

?- 4 =\= 4.
false.

?- 4 =\= 5.
true.

?- 4 >= 4.
true.

?- X = 3 * 4.
X = 3*4.

?- X is 3 * 4.
X = 12.

?- 4 is X.
ERROR: Arguments are not sufficiently instantiated
ERROR: In:
ERROR:    [8] 4 is _5128
ERROR:    [7] <user>

?- X = Y.
X = Y.

?- 3 is 1 + 2.
true.

?- 3 is +(1, 2).
true.

?- 3 is X + 2.
ERROR: Arguments are not sufficiently instantiated
ERROR: In:
ERROR:    [8] 3 is _8034+2
ERROR:    [7] <user>

?- X is 1 + 2.
X = 3.

?- 1 + 2 is 1 + 2.
false.
*/

add_3_and_double(X, Y) :- Y is (X + 3) * 2.

% ?- X is 23, Y is 41, S is X + Y.

inc :- read(X), S is X + 2, write(S).