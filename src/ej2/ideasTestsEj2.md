# Tests
Hacemos tests de las funciones por separado y de varias instancias de juego.

## Juego completo
```cpp
  TEST_G(GameTest, solve);
```
- **Ejemplos de la consigna:**

  ```cpp
    // Primer ejemplo
    struct SprinklerList sprinklers(20, 2);
    
    sprinklers.emplace(3, 5);
    sprinklers.emplace(1, 4);
    sprinklers.emplace(2, 1);
    sprinklers.emplace(2, 7);
    sprinklers.emplace(2, 10);
    sprinklers.emplace(3, 13);
    sprinklers.emplace(2, 16);
    sprinklers.emplace(4, 19);
    sprinklers.emplace(5, 3);
    sprinklers.emplace(2, 9);
    sprinklers.emplace(2, 19);
    
    EXPECT_EQUAL(sprinklers.solve(), 4);
  
    // Segundo ejemplo
    struct SprinklerList sprinklers(10, 1);
    
    sprinklers.emplace(5, 3);
    sprinklers.emplace(3, 9);
    sprinklers.emplace(1, 6);
    sprinklers.emplace(2, 1);
    sprinklers.emplace(3, 5);
    sprinklers.emplace(2, 9);
  
    EXPECT_EQUAL(sprinklers.solve(), 2);
  
    // Tercer ejemplo
    struct SprinklerList sprinklers(10, 1);
    
    sprinklers.emplace(3, 5);
    sprinklers.emplace(1, 1);
    sprinklers.emplace(1, 9);
  
    EXPECT_EQUAL(sprinklers.solve(), -1);
  
    // Cuarto ejemplo (slide)
    struct SprinklerList sprinklers(14, 4);
    
    sprinklers.emplace(3, 3);
    sprinklers.emplace(2, 5);
    sprinklers.emplace(3, 7);
    sprinklers.emplace(2, 9);
    sprinklers.emplace(3, 12);
    
    EXPECT_EQUAL(sprinklers.solve(), 3);
  ```
- **Longitud = 0:**
  ```cpp
    // l == 0 (posiciones invalidas)
    struct SprinklerList sprinklers(0, 2);
    sprinklers.emplace(3, 5);
    sprinklers.emplace(1, 4);
    sprinklers.emplace(2, 1);
    sprinklers.emplace(2, 7);
    sprinklers.emplace(4, 19);
    
    EXPECT_EQUAL(sprinklers.solve(), 0);
  
    // l == 0 (posiciones validas)
    struct SprinklerList sprinklers(0, 3);
    sprinklers.emplace(4, 0);
    sprinklers.emplace(1, 0);
    sprinklers.emplace(2, 0);
      
    EXPECT_EQUAL(sprinklers.solve(), 0);
  
    // l == 0 (posicion valida e invalida)
    struct SprinklerList sprinklers(0, 7);
    sprinklers.emplace(3, -2);
    sprinklers.emplace(10, 0);
    
    EXPECT_EQUAL(sprinklers.solve(), 0);
  ```

- **Diametro = width o suma de diametros = length:**
  ```cpp
    // Diametro de sprinklers == width
    struct SprinklerList sprinklers(3, 8);
    sprinklers.emplace(4, 0);
    sprinklers.emplace(4, 1);
    sprinklers.emplace(4, 2);
  
    EXPECT_EQUAL(sprinklers.solve(), -1);
  
    // Suma diametro de sprinklers == length
    struct SprinklerList sprinklers(16, 1);
    sprinklers.emplace(2, 2);
    sprinklers.emplace(2, 6);
    sprinklers.emplace(2, 10);
    sprinklers.emplace(2, 14);
  
    EXPECT_EQUAL(sprinklers.solve(), -1);
  
    // Suma diametro de sprinklers == length y diametro == width
    struct SprinklerList sprinklers(6, 2);
    sprinklers.emplace(1, 1);
    sprinklers.emplace(1, 3);
    sprinklers.emplace(1, 5);
  
    EXPECT_EQUAL(sprinklers.solve(), -1);
  ```
- **Solucion positiva:**
  ```cpp
    // Primer ejemplo
    struct SprinklerList sprinklers(20, 2);
    
    sprinklers.emplace(3, 5);
    sprinklers.emplace(1, 4);
    sprinklers.emplace(2, 1);
    sprinklers.emplace(2, 7);
    sprinklers.emplace(2, 10);
    sprinklers.emplace(3, 13);
    sprinklers.emplace(2, 16);
    sprinklers.emplace(4, 19);
    
    EXPECT_EQUAL(sprinklers.solve(), 6);     
  
    // Sprinkler encima de otro (uno resuelve, otro no)
    struct SprinklerList sprinklers(8, 2);
    
    sprinklers.emplace(5, 1); // mas grande, si resuelve
    sprinklers.emplace(3, 6);
    sprinklers.emplace(2, 1); // mas chico en mismo lugar que el primero (no resuelve)
   
    EXPECT_EQUAL(sprinklers.solve(), 2);
    
    // Resuelve pero se quieren cargar sprinklers con datos invalidos
    struct SprinklerList sprinklers(8, 2);
    
    sprinklers.emplace(5, 1); 
    sprinklers.emplace(3, 6);
    sprinklers.emplace(-2, 0);
    sprinklers.emplace(1, 10);
    sprinklers.emplace(-4, 18);
   
    EXPECT_EQUAL(sprinklers.solve(), 2);
  ```
## Funciones
### SprinklerList
#### SprinklerList(const ulong _l, const ulong _w);
```cpp
  TEST_SL(SprinklerListTest, SprinklerList);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```

#### emplace(const ulong r, const ulong pos);  
```cpp
  TEST_SL(SprinklerListTest, emplace);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```

### Sprinkler
#### Sprinkler(const ulong _r, const ulong _pos, const ulong w);
```cpp
  TEST_SL(SprinklerTest, Sprinkler);
```
- **Bla bla bla:**
  ```cpp
    SprinklerList list = SprinklerList(10,10);
  ```

#### operator<(const struct Sprinkler& s1);
*?Hace falta? En ningun momento se lo usa*
```cpp
  TEST_SL(SprinklerTest, operator<);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```