# Lab 7 | FOPL

> Date: Baisakh 25 | May 8

## Premises

### Premise 1

Dave and Fred are members of a dancing club in which no member can both waltz and jive. Fred's dad can't waltz and Dave can do whatever Fred can't do. If a child can do something then their parents can do it also.

**Goal**: Find a member who cannot jive.
[Solution](./Knowledge%20Base%20[1].pl)

```none
?- cannot(X, 'Jive').
X = 'Dave' ;
false.
```

### Premise 2

Find nth term of fibonacci series.
[Solution](./Knowledge%20Base%20[2].pl)

```none
?- fibonacci(5).
The 5th term is 5
true ;
```