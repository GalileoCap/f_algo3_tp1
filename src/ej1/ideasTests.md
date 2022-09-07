# Tests 
Hacemos tests de las funciones por separado y de varias instancias de juego. 

## Juego completo

## Funciones
### Map
#### Map(uint _rows,uint _cols)
#### setAt(Coord& pos, bool val)
#### getAt(Coord& pos)
#### inRange(Coord& pos)
#### canGo(Coord& pos)
#### uint freeNeighbors(Coord& pos)
#### isBlocked(Coord& pos)
#### willSplit(Coord& pos)
#### check(Coord& pos)

### Coord
#### operator-()
#### operator+(Coord& Y)
#### operator-(Coord& Y)
#### operator+=(Coord& Y)
#### operator-=(Coord& Y)
#### operator==(Coord& Y)
#### operator!=(Coord& Y)
#### toIdx(uint cols)
#### toMap(uint cols)

### Tour Counter
#### input()
#### countTours()
#### tryTo(Coord& to)
#### checkChecks()
#### check()