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
- **n > 10000:**
  ```cpp
    struct SprinklerList sprinklers(1, 2);
    
    for(int i = 0; i <= 10001; i++) {
      sprinklers.emplace(3, 1);
    }
        
    EXPECT_EQUAL(sprinklers.solve(), -1);     
  ```
## Funciones
### SprinklerList
#### SprinklerList(const ulong _l, const ulong _w);
```cpp
  TEST_SL(SprinklerListTest, SprinklerList);
```

```cpp
  // Enteros > 0
  struct SprinklerList sprinklers(8, 2);
  
  EXPECT_EQUAL(sprinklers.l, 8);
  EXPECT_EQUAL(sprinklers.w, 2);
  EXPECT_TRUE(sprinklers.queue.empty());
  // l = 0
  struct SprinklerList sprinklers(0, 5);
  
  EXPECT_EQUAL(sprinklers.l, 0);
  EXPECT_EQUAL(sprinklers.w, 5);
  EXPECT_TRUE(sprinklers.queue.empty());
  // w = 0
  struct SprinklerList sprinklers(7, 0);
  
  EXPECT_EQUAL(sprinklers.l, 7);
  EXPECT_EQUAL(sprinklers.w, 0);
  EXPECT_TRUE(sprinklers.queue.empty());

  // l = w = 0
  struct SprinklerList sprinklers(0, 0);
  
  EXPECT_EQUAL(sprinklers.l, 0);
  EXPECT_EQUAL(sprinklers.w, 0);
  EXPECT_TRUE(sprinklers.queue.empty());

  // l < 0
  struct SprinklerList sprinklers(-10, 80);
  
  EXPECT_EQUAL(sprinklers.l, -10);
  EXPECT_EQUAL(sprinklers.w, 80);
  EXPECT_TRUE(sprinklers.queue.empty());

  // w < 0
  struct SprinklerList sprinklers(310, -82313);
  
  EXPECT_EQUAL(sprinklers.l, 310);
  EXPECT_EQUAL(sprinklers.w, -82313);
  EXPECT_TRUE(sprinklers.queue.empty());
  
  // Negativo-Negativo
  struct SprinklerList sprinklers(-111, -764);
  
  EXPECT_EQUAL(sprinklers.l, -111);
  EXPECT_EQUAL(sprinklers.w, -764);
  EXPECT_TRUE(sprinklers.queue.empty());
```

#### emplace(const ulong r, const ulong pos);  
```cpp
  TEST_SL(SprinklerListTest, emplace);
```
```cpp
  // Todos sprinklers en rango
  // Ejemplo 1
  struct SprinklerList sprinklers1(10, 2);
  for(int i = 0; i <= 10; i++) {
    struct Sprinkler sprinkler(1,i,sprinklers1.w);  
    sprinklers1.emplace(1,i);
    EXPECT_TRUE((sprinklers1.queue.top().lefLim == sprinkler.leftLim) && (sprinklers1.queue.top().rightLim == sprinkler.rightLim));
  }
  
  // Ejemplo 2
  struct SprinklerList sprinklers2(10, 2);
  for(int i = 0; i <= 10; i++) {
    sprinklers2.emplace(1+i,i);
    EXPECT_TRUE((sprinklers2.queue.top().lefLim == sprinkler.leftLim) && (sprinklers2.queue.top().rightLim == sprinkler.rightLim));
  }

  // Ejemplo 3
  struct SprinklerList sprinklers3(10, 2);
  for(int i = 10; i >= 0; i--) {
    sprinklers3.emplace(1+i,i);
  }
  for(int i = 0; i <= 10; i++) {
    struct Sprinkler sprinkler(11-i,10-i,sprinklers3.w);
    EXPECT_TRUE((sprinklers3.queue.top().lefLim == sprinkler.leftLim) && (sprinklers3.queue.top().rightLim == sprinkler.rightLim));
    sprinklers3.queue.pop();
  }

  // Sprinklers encimados en la misma posicion
  // Ejemplo 1 (mas chico a mas grande)
  struct SprinklerList sprinklers4(4, 2);
  for(int i = 0; i <= 3; i++) {
    struct Sprinkler sprinkler(1+i,2,sprinklers4.w);
    sprinklers4.emplace(1+i,2);
    EXPECT_TRUE((sprinklers4.queue.top().lefLim == sprinkler.leftLim) && (sprinklers4.queue.top().rightLim == sprinkler.rightLim));
  }
  
  // Ejemplo 2 (mas grande a mas chico)
  struct SprinklerList sprinklers5(4, 2);
  for(int i = 0; i <= 3; i++) {
    struct Sprinkler sprinkler(4-i,2,sprinklers5.w);
    sprinklers5.emplace(4-i,2);
  }

  for(int i = 0; i <= 3; i++) {
    struct Sprinkler sprinkler(4-i,2,sprinklers5.w);
    EXPECT_TRUE((sprinklers5.queue.top().lefLim == sprinkler.leftLim) && (sprinklers5.queue.top().rightLim == sprinkler.rightLim));
    sprinklers5.queue.pop();
  }
  
  // Ejemplo 3 (todos iguales)
  struct SprinklerList sprinklers6(7, 3);
  for(int i = 0; i <= 3; i++) {
    sprinklers6.emplace(1,3);
  }
  
  EXPECT_EQUAL(sprinklers6.queue.size(), 4);
  
  for(int i = 0; i <= 3; i++) {
    struct Sprinkler sprinkler(1,3,sprinklers6.w);
    EXPECT_TRUE((sprinklers6.queue.top().lefLim == sprinkler.leftLim) && (sprinklers6.queue.top().rightLim == sprinkler.rightLim));
    sprinklers6.queue.pop();
  }
  
  // Sprinklers en l = 0 o l = |l|
  struct SprinklerList sprinklers7(5, 1);
  sprinklers7.emplace(1,0);
  sprinklers7.emplace(1,5);
  EXPECT_TRUE(sprinklers7.queue.size() == 2);
  
  // Sprinklers fuera de rango (l y w positivos)
  struct SprinklerList sprinklers8(8, 2);
  sprinklers8.emplace(1,12);
  sprinklers8.emplace(1,20);
  EXPECT_TRUE(sprinklers8.queue.size() == 0);
  
  // Sprinklers fuera de rango (pos negativa)
  struct SprinklerList sprinklers9(3, 4);
  sprinklers9.emplace(4,-8);
  sprinklers9.emplace(4,-10);
  EXPECT_TRUE(sprinklers9.queue.size() == 0);
  
  // Sprinklers fuera de rango (r negativo)
  struct SprinklerList sprinklers10(7, 4);
  sprinklers10.emplace(-2,2);
  sprinklers10.emplace(-6,1);
  EXPECT_TRUE(sprinklers10.queue.size() == 0);
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
```cpp
  TEST_SL(SprinklerTest, operator<);
```
- **Bla bla bla:**
  ```cpp
    // inserte su test aqui 
  ```