factorial(0, 1).    % Base/Stopping condition for recursion
factorial(N, F):-
    N > 0,
    N1 is N - 1,
    factorial(N1, F1),
    F is N * F1.

digitsSum(0, 0).
digitsSum(N, R):-
    N > 0,
    R1 is (N / 10),
    digitsSum(R1, R2),
    R is R1 + R2.
