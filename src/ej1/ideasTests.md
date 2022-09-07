# Tests 
Hacemos tests de las funciones por separado y de varias instancias de juego. 

## Juego completo

## Funciones
### Map
#### Map(uint _rows,uint _cols)
```cpp
  TEST_M(MapTest, Map);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### setAt(Coord& pos, bool val)
```cpp
  TEST_M(MapTest, setAt);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### getAt(Coord& pos)
```cpp
  TEST_M(MapTest, getAt);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### inRange(Coord& pos)
```cpp
  TEST_M(MapTest, inRange);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### canGo(Coord& pos)
```cpp
  TEST_M(MapTest, canGo);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### uint freeNeighbors(Coord& pos)
```cpp
  TEST_M(MapTest, freeNeighbors);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### isBlocked(Coord& pos)
```cpp
  TEST_M(MapTest, isBlocked);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### willSplit(Coord& pos)
```cpp
  TEST_M(MapTest, willSplit);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### check(Coord& pos)
```cpp
  TEST_M(MapTest, check);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
  
### Coord
#### manhattan(Coord& Y) 
```cpp
  TEST_C(CoordenadaTest, manhattan);
```
*Tener en cuenta que esta funcion dara la distancia aunque la posicion **'y'** este fuera del mapa.*

- **Mismo casillero:**
    ```cpp
    // Ambos nulos
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(0,0);
    
    // Ambos positivos (no cero)
    Coord inicio2 = Coord(3,8);
    Coord final2 = Coord(3,8);
    
    // Ambos negativos
    Coord inicio3 = Coord(-6,-1);
    Coord final3 = Coord(-6,-1);
  
    // X negativo e Y positivo
    Coord inicio4 = Coord(-2,9);
    Coord final4 = Coord(-2,9); 
  
    // X positivo e Y negativo
    Coord inicio5 = Coord(7,-3);
    Coord final5 = Coord(7,-3); 
    
    // QUE DEBERIA DEVOLVER SI PONGO (-0,-0)?? 
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
    uint manhattanDistance5 = inicio5.manhattan(final5);
  
    EXPECT_EQ(manhattanDistance1, 0);
    EXPECT_EQ(manhattanDistance2, 0);
    EXPECT_EQ(manhattanDistance3, 0);
    EXPECT_EQ(manhattanDistance4, 0);
    EXPECT_EQ(manhattanDistance5, 0);
    ```
- **Arriba:** 
    ```cpp
    // Desde comienzo del mapa
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(0,4);
    
    // Desde el final
    Coord inicio2 = Coord(1,0);
    Coord final2 = Coord(1,5);
    
    // Desde una posicion random (puede o no estar en un mapa)
    Coord inicio3 = Coord(2,3);
    Coord final3 = Coord(2,10);
  
    // Desde una posicion invalida para un mapa
    Coord inicio4 = Coord(-2,-6);
    Coord final4 = Coord(-2,-3);
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
  
    EXPECT_EQ(manhattanDistance1, 4);
    EXPECT_EQ(manhattanDistance2, 5);
    EXPECT_EQ(manhattanDistance3, 7);
    EXPECT_EQ(manhattanDistance4, 3);
    ```
- **Abajo:**
    ```cpp
    // Desde comienzo del mapa
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(0,-1);
    
    // Desde el final
    Coord inicio2 = Coord(1,0);
    Coord final2 = Coord(1,-1);
    
    // Desde una posicion random (puede o no estar en un mapa)
    Coord inicio3 = Coord(2,3);
    Coord final3 = Coord(2,1);
  
    // Desde una posicion invalida para un mapa
    Coord inicio4 = Coord(-2,-6);
    Coord final4 = Coord(-2,-10);
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
  
    EXPECT_EQ(manhattanDistance1, 1);
    EXPECT_EQ(manhattanDistance2, 1);
    EXPECT_EQ(manhattanDistance3, 2);
    EXPECT_EQ(manhattanDistance4, 4);
    ```
- **Izquierda:**
    ```cpp
    // Desde comienzo del mapa
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(-3,0);
    
    // Desde el final
    Coord inicio2 = Coord(1,0);
    Coord final2 = Coord(0,0);
    
    // Desde una posicion random (puede o no estar en un mapa)
    Coord inicio3 = Coord(8,1);
    Coord final3 = Coord(2,1);
  
    // Desde una posicion invalida para un mapa
    Coord inicio4 = Coord(-2,-6);
    Coord final4 = Coord(-7,-6);
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
  
    EXPECT_EQ(manhattanDistance1, 3);
    EXPECT_EQ(manhattanDistance2, 1);
    EXPECT_EQ(manhattanDistance3, 6);
    EXPECT_EQ(manhattanDistance4, 5);
    ```
- **Derecha:**
    ```cpp
    // Desde comienzo del mapa
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(0,4);
    
    // Desde el final
    Coord inicio2 = Coord(1,0);
    Coord final2 = Coord(1,3);
    
    // Desde una posicion random (puede o no estar en un mapa)
    Coord inicio3 = Coord(8,1);
    Coord final3 = Coord(8,20);
  
    // Desde una posicion invalida para un mapa
    Coord inicio4 = Coord(-2,-6);
    Coord final4 = Coord(-2,-1);
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
  
    EXPECT_EQ(manhattanDistance1, 4);
    EXPECT_EQ(manhattanDistance2, 3);
    EXPECT_EQ(manhattanDistance3, 19);
    EXPECT_EQ(manhattanDistance4, 5);
    ```
- **Diagonal:**
    ```cpp
    // Desde comienzo del mapa (der-arriba)
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(1,1);
    
    // Desde el final (izq-arriba)
    Coord inicio2 = Coord(1,0);
    Coord final2 = Coord(0,1);
    
    // Desde una posicion random (puede o no estar en un mapa) (izq-abajo)
    Coord inicio3 = Coord(8,1);
    Coord final3 = Coord(7,0);
  
    // Desde una posicion invalida para un mapa (izq-arriba)
    Coord inicio4 = Coord(-2,-6);
    Coord final4 = Coord(-3,-5);
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
  
    EXPECT_EQ(manhattanDistance1, 2);
    EXPECT_EQ(manhattanDistance2, 2);
    EXPECT_EQ(manhattanDistance3, 2);
    EXPECT_EQ(manhattanDistance4, 2);
    ```
- **Diagonal Far:**
    ```cpp
    // Desde comienzo del mapa (der-arriba)
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(5,5);
    
    // Desde el final (izq-arriba)
    Coord inicio2 = Coord(1,0);
    Coord final2 = Coord(-3,4);
    
    // Desde una posicion random (puede o no estar en un mapa) (izq-abajo)
    Coord inicio3 = Coord(8,1);
    Coord final3 = Coord(2,-5);
  
    // Desde una posicion invalida para un mapa (izq-arriba)
    Coord inicio4 = Coord(-2,-6);
    Coord final4 = Coord(-9,1);
  
    uint manhattanDistance1 = inicio1.manhattan(final1);
    uint manhattanDistance2 = inicio2.manhattan(final2);
    uint manhattanDistance3 = inicio3.manhattan(final3);
    uint manhattanDistance4 = inicio4.manhattan(final4);
  
    EXPECT_EQ(manhattanDistance1, 10);
    EXPECT_EQ(manhattanDistance2, 8);
    EXPECT_EQ(manhattanDistance3, 12);
    EXPECT_EQ(manhattanDistance4, 14);
    ```
#### operator-()
```cpp
  TEST_C(CoordenadaTest, -operator);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### operator+(Coord& Y)
```cpp
  TEST_C(CoordenadaTest, operator+);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### operator-(Coord& Y)
```cpp
  TEST_C(CoordenadaTest, operator-);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### operator+=(Coord& Y)
```cpp
  TEST_C(CoordenadaTest, operator+=);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### operator-=(Coord& Y)
```cpp
  TEST_C(CoordenadaTest, operator-=);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### operator==(Coord& Y)
```cpp
  TEST_C(CoordenadaTest, operator==);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### operator!=(Coord& Y)
```cpp
  TEST_C(CoordenadaTest, operator!=);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### toIdx(uint cols)
```cpp
  TEST_C(CoordenadaTest, toIdx);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### toMap(uint cols)
```cpp
  TEST_C(CoordenadaTest, toMap);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```

### Tour Counter
#### input()
```cpp
  TEST_TC(TourCounterTest, input);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### countTours()
```cpp
  TEST_TC(TourCounterTest, countTours);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### tryTo(Coord& to)
```cpp
  TEST_TC(TourCounterTest, tryTo);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### checkChecks()
```cpp
  TEST_TC(TourCounterTest, checkChecks);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```
#### check()
```cpp
  TEST_TC(TourCounterTest, check);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```