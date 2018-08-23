% display average of 2 numbers
avg :-
	write("Enter X: "),
	read(X),
	write("Enter Y: "),
	read(Y),
	Average is (X + Y) / 2,
	write("Average: "),
	write(Average).

% check whether triangle exists or not
check_triangle :-
	write("Enter length of first side: "),
	read(A),
	write("Enter length of second side: "),
	read(B),
	write("Enter length of third side: "),
	read(C),
	(A + B > C, A + C > B, B + C > A) ->
		write("It is a valid triangle.");
		write("It is not a valid triangle.").

% check if divisible by 3 and 5
check_divisible :-
	read(X),
	A is mod(X, 3),
	B is mod(X, 5),
	( A =:= 0, B =:= 0) ->
		write("Divisible by both 3 and 5.");
		write("Not divisible by either 3 or 5 or both."). 

% exmaple if condition
if(X) :-
	X -> true; false.