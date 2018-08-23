happy(ram).
listen2music(hari).
playsAirGuitar(ram):-
	listen2music(ram),
	happy(ram).
playsAirGuitar(hari):-
	happy(hari);
	listen2music(hari).

% playsAirGuitar(hari):-
% 	happy(hari).
% playsAirGuitar(hari):-
% 	listen2music(hari).