# Facts and Rules in PROLOG 
## Consider a knowledge base
happy(ram).
listen2music(hari).
listen2music(ram):-happy(ram).
playsAirGuitar(hari):-listen2music(hari).
playsAirGuitar(ram):-listen2music(ram).

## Queries
?- happy(ram).  
?- listen2music(ram).  
?- listen2music(hari).  
?- playsAirGuitar(ram).  
?- playsAirGuitar(hari).  
?- playsAirGuitar(X).  

_NOTE_  
`head:-body` _[equivalent to head->body]_  
`head` is true iff `body` is true.