# Conjunction of Disjunction in PROLOG

## Knowledge Base
```
happy(ram).  
listen2music(hari).  
playsAirGuitar(ram):-  
	listen2music(ram),  
	happy(ram).  
playsAirGuitar(hari):-  
	happy(hari).  
playsAirGuitar(hari):-  
	listen2music(hari).  
```

## Querys
`?- playsAirGuitar(hari).`  
	true  
`?- playsAirGuitar(ram).`  
	false  
`?- listen2music(hari).`  
	true  
`?- listen2music(ram).`  
	false  
`?- happy(ram).`  
	true  
`?- happy(hari).`  
	false

## Notes
- Comma (,) is used for conjunction in PROLOG. Like logical AND operator
- Semicolon (;) is used for disjunction in PROLOG. Like logical OR operator.