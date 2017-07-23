happy(ram).
listen2music(hari).
listen2music(ram):-happy(ram).
playsAirGuitar(hari):-listen2music(hari).
playsAirGuitar(ram):-listen2music(ram).