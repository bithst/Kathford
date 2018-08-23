# Using variables in knowledge base and query

## Knowledge Base
woman(sita).
woman(gita).
woman(rita).
loves(ram,sita).
loves(hari,sita).
loves(sita,ram).

# Questions
1. List the names of all women in above KB.

```PROLOG
?- woman(X)
	X=sita;
	X=gita;
	X=rita.
```

2. Find an individual 'X' such that 'ram' loves 'X' and 'X' is an woman.

```PROLOG
?- loves(ram, X), woman(X)
	X=sita.
```

3. Define a rule in above KB showing that 'X' is jealous of 'Y' if 'X' loves 'Z' and 'Y' loves 'Z'.

```PROLOG
?- jelous(hari, X)
	X=ram.
```