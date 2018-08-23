# Lab 2 | Artificial Intelligence

Knowledge inference in PROLOG
> Date: Falgun 22 | March 6

## Queries and Results

### Knowledge Base 1

Parent of Bob

```none
?- parent(X, bob).
X = pam ;
X = tom.
```

### Kowledge Base 2

Was James I the parent of Charles I?

```none
?- parent(james_i, charles_i).
true.
```

Who was Charles I's parent?

```none
?- parent(X, charles_i).
X = james_i.
```

Who were the children of Charles I?

```none
?- parent(charles_i, X).
X = catherine ;
X = charles_ii ;
X = james_ii.
```

### Knowledge Base 3

Checking factorial of 12

```none
?- factorial(12, F).
F = 479001600 ;
false.
```