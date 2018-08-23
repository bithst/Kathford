# Lab 4 | List and Recursion

>Date: Chaitra 27 | April 10

## Code

### List

1. List with string `[a, b, c]`
2. List with variables `[A, B, C]`

### Try

Seperating

```prolog
[H|T] = [a, b, c, d, e].

H = a
T = [b, c, d, e]
```

Matching

```prolog
[A, B, C, D, E] = [1, 2, 3, 4, 5].
```

Appending

```prolog
append([a, b], [c, d], X).
```

## Querys

Seperating head and tail

```none
?- [H|T] = [a, b, c, d, e].
H = a,
T = [b, c, d, e].
```

Assigning values from a list to another list of variables

```none
?- [A, B, C, D, E] = [1, 2, 3, 4, 5].
A = 1,
B = 2,
C = 3,
D = 4,
E = 5.
```

Appending values to a list

```none
% No variable defined at the end.
?- append([a, b], [c, d]).
false.

?- append([a, b], [c, d], X).
X = [a, b, c, d].
```

Find sum, sum of even numbers and sum of square of numbers in a list

```none
?- sum([1, 2, 3, 5, 6], X).
X = 17.

?- sum_even([1, 2, 3, 4], X).
X = 6.

?- sum_square([1, 2, 3, 6], X).
X = 50.
```