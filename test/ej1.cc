#include "gtest-1.8.1/gtest.h"
#include "../src/ej1/tourCounter.h"

// TESTS GLOBALES
TEST(GameTest, dosPorN) {
    TourCounter tc;

    // 2x4
    tc.inputTests(2,4,Coord(0,1),Coord(2,1),Coord(3,0));
    EXPECT_EQ(tc.countTours(), 1);

    // 2x5
    tc.inputTests(2,5,Coord(0,1),Coord(3,1),Coord(4,0));
    EXPECT_EQ(tc.countTours(), 1);

    // 2x6
    tc.inputTests(2,6,Coord(1,1),Coord(4,1),Coord(4,0));
    EXPECT_EQ(tc.countTours(), 1);

    // 2x7
    tc.inputTests(2,7,Coord(1,1),Coord(5,1),Coord(5,0));
    EXPECT_EQ(tc.countTours(), 1);

    // 2x8
    tc.inputTests(2,8,Coord(2,1),Coord(6,1),Coord(5,0));
    EXPECT_EQ(tc.countTours(), 1);
}

TEST(GameTest, tresPorN) {
    TourCounter tc;

    // 3x4
    tc.inputTests(3,4,Coord(0,2),Coord(2,1),Coord(3,1));
    EXPECT_EQ(tc.countTours(), 1);

    // 3x6 (el del enunciado)
    tc.inputTests(3,6,Coord(1,2),Coord(4,2),Coord(4,0));
    EXPECT_EQ(tc.countTours(), 2);

    // 3x8
    tc.inputTests(3,8,Coord(2,1),Coord(5,2),Coord(7,0));
    EXPECT_EQ(tc.countTours(), 1);
}

TEST(GameTest, cuatroPorN) {
    TourCounter tc;

    // 4x4
    tc.inputTests(4,4,Coord(1,2),Coord(2,3),Coord(2,1));
    EXPECT_EQ(tc.countTours(), 1);

    tc.inputTests(4,4,Coord(0,3),Coord(2,1),Coord(3,2));
    EXPECT_EQ(tc.countTours(), 1);

    tc.inputTests(4,4,Coord(2,1),Coord(0,3),Coord(3,2));
    EXPECT_EQ(tc.countTours(), 1);

    // 4x5
    tc.inputTests(4,5,Coord(1,3),Coord(2,3),Coord(3,1));
    EXPECT_EQ(tc.countTours(), 1);
}

// TEST(GameTest, cincoPorN) {}

// TEST(GameTest, seisPorN) {}

// TEST(GameTest, sietePorN) {}

// TEST(GameTest, ochoPorOcho) {}

// TESTS UNITARIOS

// MAPA
// setAt(Coord& pos, bool val)
TEST(MapTest, setAt) {
    Map mapa = Map(4,4);
    // Mapa sin celdas visitadas
    Coord coordenada1 = Coord(1,2);
    mapa.setAt(coordenada1, true);
    bool result = (mapa.hash & coordenada1.toMap(4)) == coordenada1.toMap(4);
    EXPECT_TRUE(result);
    // Seteo verdadera celda ya verdadera
    mapa.setAt(coordenada1, true);
    result = (mapa.hash & coordenada1.toMap(4)) == coordenada1.toMap(4);
    EXPECT_TRUE(result);
    // Seteo falsa celda ya falsa
    Coord coordenada2 = Coord(0,3);
    mapa.setAt(coordenada2, false);
    result = (bool)(~(mapa.hash & coordenada2.toMap(4)));
    EXPECT_TRUE(result);
    // Seteo verdadera a falsa
    mapa.setAt(coordenada1, false);
    result = (bool)(~(mapa.hash & coordenada1.toMap(4)));
    EXPECT_TRUE(result);
}

// getAt(Coord& pos)
TEST(MapTest, getAt) {
    // Mapa vacio
    Map mapa1 = Map(3,6);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            EXPECT_TRUE(!(mapa1.getAt(Coord(j,i))));
        }
    }

    // Mapa todo lleno
    Map mapa2 = Map(8,8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mapa2.setAt(Coord(j,i),true);
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            EXPECT_TRUE((mapa2.getAt(Coord(j,i))));
        }
    }
}

// inRange(Coord& pos)
TEST(MapTest, inRangeCuadrado) {
    // Mapa de kxk
    for (int k = 2; k < 9; k++) {
        Map mapa = Map(k,k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
            // Todas dentro del rango
            EXPECT_TRUE(mapa.inRange(Coord(j,i)));
            // X negativa, Y en rango
            EXPECT_FALSE(mapa.inRange(Coord(-j,i)));
            // X en rango, Y negativa
            EXPECT_FALSE(mapa.inRange(Coord(j,-i)));
            // Ambas negativas
            EXPECT_FALSE(mapa.inRange(Coord(-j,-i)));
            // Posicion con X se paso de limite, Y no
            EXPECT_FALSE(mapa.inRange(Coord(k+j,i)));
            // Posicion con X en rango, Y se paso
            EXPECT_FALSE(mapa.inRange(Coord(j,k+i)));
            // Posicion con X e Y pasadas de limite
            EXPECT_FALSE(mapa.inRange(Coord(k+j,k+i)));
            }
        }
    }
}

TEST(MapTest, inRangeRectangular) {
    // Mapa de qxk (q < k)
    for (int q = 2; q < 8; q++) {
        for (int k = q+1; k < 9; k++) {
            Map mapa = Map(q,k);
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < k; j++) {
                    // Todas dentro del rango
                    EXPECT_TRUE(mapa.inRange(Coord(j,i)));
                    // X negativa, Y en rango
                    EXPECT_FALSE(mapa.inRange(Coord(-j,i)));
                    // X en rango, Y negativa
                    EXPECT_FALSE(mapa.inRange(Coord(j,-i)));
                    // Ambas negativas
                    EXPECT_FALSE(mapa.inRange(Coord(-j,-i)));
                    // Posicion con X se paso de limite, Y no
                    EXPECT_FALSE(mapa.inRange(Coord(k+j,i)));
                    // Posicion con X en rango, Y se paso
                    EXPECT_FALSE(mapa.inRange(Coord(j,q+i)));
                    // Posicion con X e Y pasadas de limite
                    EXPECT_FALSE(mapa.inRange(Coord(k+j,q+i)));
                }
            }
        }
    }
}

// canGo(Coord& pos)
TEST(MapTest, canGoCuadrado) {
    // Mapa de kxk vacio
    for (int k = 2; k < 9; k++) {
        Map mapa = Map(k,k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                // Coordenada actual
                EXPECT_TRUE(mapa.canGo(Coord(j,i)));
                // X negativa, Y en rango
                EXPECT_FALSE(mapa.canGo(Coord(-j,i)));
                // X en rango, Y negativa
                EXPECT_FALSE(mapa.canGo(Coord(j,-i)));
                // Ambas negativas
                EXPECT_FALSE(mapa.canGo(Coord(-j,-i)));
                // Posicion con X se paso de limite, Y no
                EXPECT_FALSE(mapa.canGo(Coord(k+j,i)));
                // Posicion con X en rango, Y se paso
                EXPECT_FALSE(mapa.canGo(Coord(j,k+i)));
                // Posicion con X e Y pasadas de limite
                EXPECT_FALSE(mapa.canGo(Coord(k+j,k+i)));
            }
        }
    }
    // Mapa de kxk lleno
    for (int k = 2; k < 9; k++) {
        Map mapa = Map(k,k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                mapa.setAt(Coord(j,i), true);
                // Coordenada actual
                EXPECT_FALSE(mapa.canGo(Coord(j,i)));
            }
        }
    }
}

TEST(MapTest, canGoRectangular) {
    // Mapa de qxk (q < k) vacio
    for (int q = 2; q < 8; q++) {
        for (int k = q+1; k < 9; k++) {
            Map mapa = Map(q,k);
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < k; j++) {
                    // Coordenada actual
                    EXPECT_TRUE(mapa.canGo(Coord(j,i)));
                    // X negativa, Y en rango
                    EXPECT_FALSE(mapa.canGo(Coord(-j,i)));
                    // X en rango, Y negativa
                    EXPECT_FALSE(mapa.canGo(Coord(j,-i)));
                    // Ambas negativas
                    EXPECT_FALSE(mapa.canGo(Coord(-j,-i)));
                    // Posicion con X se paso de limite, Y no
                    EXPECT_FALSE(mapa.canGo(Coord(k+j,i)));
                    // Posicion con X en rango, Y se paso
                    EXPECT_FALSE(mapa.canGo(Coord(j,q+i)));
                    // Posicion con X e Y pasadas de limite
                    EXPECT_FALSE(mapa.canGo(Coord(k+j,q+i)));
                }
            }
        }
    }
    // Mapa de qxk (q < k) lleno
    for (int q = 2; q < 8; q++) {
        for (int k = q+1; k < 9; k++) {
            Map mapa = Map(q,k);
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < k; j++) {
                    mapa.setAt(Coord(j,i), true);
                    // Coordenada actual
                    EXPECT_FALSE(mapa.canGo(Coord(j,i)));
                }
            }
        }
    }
}

// freeNeighbors(Coord& pos)
TEST(MapTest, freeNeighborsCentro) {
    Map mapa = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(1,1) && Coord(1,1).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa.freeNeighbors(Coord(1,1)), 4 - vecinosOcupados);
        }
    }
}

TEST(MapTest, freeNeighborsCorners) {
    // Abajo izquierda
    Map mapa2 = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa2.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(0,0) && Coord(0,0).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa2.freeNeighbors(Coord(0,0)), 2 - vecinosOcupados);
        }
    }
    // Abajo derecha
    Map mapa3 = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa3.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(2,0) && Coord(2,0).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa3.freeNeighbors(Coord(2,0)), 2 - vecinosOcupados);
        }
    }
    // Arriba izquierda
    Map mapa4 = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa4.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(0,2) && Coord(0,2).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa4.freeNeighbors(Coord(0,2)), 2 - vecinosOcupados);
        }
    }
    // Arriba derecha
    Map mapa5 = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa5.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(2,2) && Coord(2,2).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa5.freeNeighbors(Coord(2,2)), 2 - vecinosOcupados);
        }
    }
}

TEST(MapTest, freeNeighborsArriba) {
    Map mapa = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(1,2) && Coord(1,2).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa.freeNeighbors(Coord(1,2)), 3 - vecinosOcupados);
        }
    }
}

TEST(MapTest, freeNeighborsAbajo) {
    Map mapa = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa.setAt(Coord(j,i),true);
            if(Coord(j,i) != Coord(1,0) && Coord(1,0).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa.freeNeighbors(Coord(1,0)), 3 - vecinosOcupados);
        }
    }
}

TEST(MapTest, freeNeighborsIzq) {
    Map mapa = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa.setAt(Coord(j,i), true);
            if(Coord(j,i) != Coord(0,1) && Coord(0,1).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa.freeNeighbors(Coord(0,1)), 3 - vecinosOcupados);
        }
    }
}

TEST(MapTest, freeNeighborsDer) {
    Map mapa = Map(3,3);
    for(int i = 0; i < 3; i++) {
        int vecinosOcupados = 0;
        for(int j = 0; j < 3; j++) {
            mapa.setAt(Coord(j,i), true);
            if(Coord(j,i) != Coord(2,1) && Coord(2,1).manhattan(Coord(j,i) == 1)) {
                vecinosOcupados++;
            }
            EXPECT_EQ(mapa.freeNeighbors(Coord(2,1)), 3 - vecinosOcupados);
        }
    }
}

// isBlocked(Coord& pos)
TEST(MapTest, isBlocked1) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,0), true);
    mapa.setAt(Coord(2,0), true);
    mapa.setAt(Coord(1,1), true);
    EXPECT_TRUE(mapa.isBlocked(Coord(1,0)));
}

TEST(MapTest, isBlocked2) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,0), true);
    mapa.setAt(Coord(1,1), true);
    EXPECT_FALSE(mapa.isBlocked(Coord(1,0)));
}

TEST(MapTest, isBlocked3) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,0), true);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,2), true);
    mapa.setAt(Coord(2,1), true);
    EXPECT_TRUE(mapa.isBlocked(Coord(1,1)));
}

TEST(MapTest, isBlocked4) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,0), true);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,2), true);
    EXPECT_FALSE(mapa.isBlocked(Coord(1,1)));
}

TEST(MapTest, isBlocked5) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,0), true);
    EXPECT_TRUE(mapa.isBlocked(Coord(0,0)));
}

TEST(MapTest, isBlocked6) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,1), true);
    EXPECT_FALSE(mapa.isBlocked(Coord(0,0)));
}

TEST(MapTest, isBlocked7) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,2), true);
    EXPECT_TRUE(mapa.isBlocked(Coord(0,2)));
}

TEST(MapTest, isBlocked8) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,2), true);
    EXPECT_FALSE(mapa.isBlocked(Coord(0,2)));
}

TEST(MapTest, isBlocked9) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(1,2), true);
    EXPECT_TRUE(mapa.isBlocked(Coord(2,2)));
}

TEST(MapTest, isBlocked10) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,2), true);
    EXPECT_FALSE(mapa.isBlocked(Coord(2,2)));
}

TEST(MapTest, isBlocked11) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(1,0), true);
    EXPECT_TRUE(mapa.isBlocked(Coord(2,2)));
}

TEST(MapTest, isBlocked12) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    EXPECT_FALSE(mapa.isBlocked(Coord(2,2)));
}

// willSplit(Coord& pos)
TEST(MapTest, willSplit1) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(0,1), true);
    EXPECT_TRUE(mapa.willSplit(Coord(1,1)));
}

TEST(MapTest, willSplit2) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,1), true);
    EXPECT_FALSE(mapa.willSplit(Coord(1,1)));
}

TEST(MapTest, willSplit3) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    EXPECT_FALSE(mapa.willSplit(Coord(1,1)));
}

TEST(MapTest, willSplit4) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,2), true);
    mapa.setAt(Coord(1,0), true);
    EXPECT_TRUE(mapa.willSplit(Coord(1,1)));
}

TEST(MapTest, willSplit5) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,2), true);
    EXPECT_FALSE(mapa.willSplit(Coord(1,1)));
}

TEST(MapTest, willSplit6) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,0), true);
    EXPECT_FALSE(mapa.willSplit(Coord(1,1)));
}

// check(Coord& pos)
TEST(MapTest, check1) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,2), true);
    mapa.setAt(Coord(1,0), true);
    EXPECT_FALSE(mapa.check(Coord(1,1)));
}

TEST(MapTest, check2) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(0,1), true);
    EXPECT_FALSE(mapa.check(Coord(1,1)));
}

TEST(MapTest, check3) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,0), true);
    mapa.setAt(Coord(2,0), true);
    mapa.setAt(Coord(1,1), true);
    EXPECT_FALSE(mapa.check(Coord(1,0)));
}

TEST(MapTest, check4) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(1,0), true);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,2), true);
    mapa.setAt(Coord(2,1), true);
    EXPECT_FALSE(mapa.check(Coord(1,1)));
}

TEST(MapTest, check5) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,0), true);
    EXPECT_FALSE(mapa.check(Coord(0,0)));
}

TEST(MapTest, check6) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(1,2), true);
    EXPECT_FALSE(mapa.check(Coord(0,2)));
}

TEST(MapTest, check7) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(1,2), true);
    EXPECT_FALSE(mapa.check(Coord(2,2)));
}

TEST(MapTest, check8) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(1,0), true);
    EXPECT_FALSE(mapa.check(Coord(2,2)));
}

TEST(MapTest, check9) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,0), true);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(0,2), true);
    mapa.setAt(Coord(1,2), true);
    mapa.setAt(Coord(2,0), true);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(2,2), true);
    EXPECT_TRUE(mapa.check(Coord(1,1)));
}

TEST(MapTest, check10) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,0), true);
    mapa.setAt(Coord(0,1), true);
    mapa.setAt(Coord(0,2), true);
    mapa.setAt(Coord(1,1), true);
    mapa.setAt(Coord(1,2), true);
    mapa.setAt(Coord(2,1), true);
    mapa.setAt(Coord(2,2), true);
    EXPECT_TRUE(mapa.check(Coord(2,0)));
}

TEST(MapTest, check11) {
    Map mapa = Map(3,3);
    mapa.setAt(Coord(0,0), true);
    EXPECT_TRUE(mapa.check(Coord(0,1)));
}

// COORD
// manhattan(Coord& Y)
TEST(CoordenadaTest, manhattanMismoCasillero) {
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
}

TEST(CoordenadaTest, manhattanArriba) {
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
}

TEST(CoordenadaTest, manhattanAbajo) {
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
}

TEST(CoordenadaTest, manhattanIzq) {
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
}

TEST(CoordenadaTest, manhattanDer) {
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
}

TEST(CoordenadaTest, manhattanDiag) {
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
}

TEST(CoordenadaTest, manhattanDiagFar) {
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
}

// operator-()
TEST(CoordenadaTest, minusOperator) {
    // Nulo
    Coord inicio1 = Coord(0,0);
    Coord final1 = Coord(0,0);
    // Todos positivos
    Coord inicio2 = Coord(2,3);
    Coord final2 = Coord(-2,-3);
    // Todos negativos
    Coord inicio3 = Coord(4,2);
    Coord final3 = Coord(-4,-2);
    // X positivo, Y negativo
    Coord inicio4 = Coord(1,-5);
    Coord final4 = Coord(-1,5);
    // X negativo, Y positivo
    Coord inicio5 = Coord(-3,2);
    Coord final5 = Coord(3,-2);

    -inicio1;
    -inicio2;
    -inicio3;
    -inicio4;
    -inicio5;

    // Estan bien los "EXPECT_EQ"? O primero deberia utilizar el comando == de
    // coord y luego poner "EXPECT_TRUE"?
    EXPECT_EQ(inicio1, final1);
    EXPECT_EQ(inicio2, final2);
    EXPECT_EQ(inicio3, final3);
    EXPECT_EQ(inicio4, final4);
    EXPECT_EQ(inicio5, final5);
}

// operator+(Coord& Y)
TEST(CoordenadaTest, operatorPlus) {
    // Nulo
    Coord primero1 = Coord(4,3);
    Coord primero2 = Coord(0,0);
    Coord finalPrimero = Coord(4,3);
    // Nulo bis
    Coord segundo1 = Coord(-2,-3);
    Coord segundo2 = Coord(0,0);
    Coord finalSegundo = Coord(-2,-3);
    // Todos positivos
    Coord tercero1 = Coord(4,2);
    Coord tercero2 = Coord(1,3);
    Coord finalTercero = Coord(5,5);
    // Todos negativos
    Coord cuarto1 = Coord(-1,-5);
    Coord cuarto2 = Coord(1,5);
    Coord finalCuarto = Coord(0,0);
    // X positivo, Y negativo
    Coord quinto1 = Coord(3,-7);
    Coord quinto2 = Coord(1,-1);
    Coord finalQuinto = Coord(4,-8);
    // X negativo, Y positivo
    Coord sexto1 = Coord(-3,2);
    Coord sexto2 = Coord(6,-2);
    Coord finalSexto = Coord(3,0);

    primero1 = primero1 + primero2;
    segundo1 = segundo1 + segundo2;
    tercero1 = tercero1 + tercero2;
    cuarto1 = cuarto1 + cuarto2;
    quinto1 = quinto1 + quinto2;
    sexto1 = sexto1 + sexto2;

    // Estan bien los "EXPECT_EQ"? O primero deberia utilizar el comando == de
    // coord y luego poner "EXPECT_TRUE"?
    EXPECT_EQ(primero1, finalPrimero);
    EXPECT_EQ(segundo1, finalSegundo);
    EXPECT_EQ(tercero1, finalTercero);
    EXPECT_EQ(cuarto1, finalCuarto);
    EXPECT_EQ(quinto1, finalQuinto);
    EXPECT_EQ(sexto1, finalSexto);
}

// operator-(Coord& Y)
TEST(CoordenadaTest, operatorMinus) {
    // Nulo
    Coord primero1 = Coord(4,3);
    Coord primero2 = Coord(0,0);
    Coord finalPrimero = Coord(4,3);
    // Nulo bis
    Coord segundo1 = Coord(-2,-3);
    Coord segundo2 = Coord(0,0);
    Coord finalSegundo = Coord(-2,-3);
    // Todos positivos
    Coord tercero1 = Coord(4,2);
    Coord tercero2 = Coord(1,3);
    Coord finalTercero = Coord(3,-1);
    // Todos negativos
    Coord cuarto1 = Coord(-1,-5);
    Coord cuarto2 = Coord(1,5);
    Coord finalCuarto = Coord(-2,-10);
    // X positivo, Y negativo
    Coord quinto1 = Coord(3,-7);
    Coord quinto2 = Coord(1,-1);
    Coord finalQuinto = Coord(2,-6);
    // X negativo, Y positivo
    Coord sexto1 = Coord(-3,2);
    Coord sexto2 = Coord(6,-2);
    Coord finalSexto = Coord(-9,4);

    primero1 = primero1 - primero2;
    segundo1 = segundo1 - segundo2;
    tercero1 = tercero1 - tercero2;
    cuarto1 = cuarto1 - cuarto2;
    quinto1 = quinto1 - quinto2;
    sexto1 = sexto1 - sexto2;

    // Estan bien los "EXPECT_EQ"? O primero deberia utilizar el comando == de
    // coord y luego poner "EXPECT_TRUE"?
    EXPECT_EQ(primero1, finalPrimero);
    EXPECT_EQ(segundo1, finalSegundo);
    EXPECT_EQ(tercero1, finalTercero);
    EXPECT_EQ(cuarto1, finalCuarto);
    EXPECT_EQ(quinto1, finalQuinto);
    EXPECT_EQ(sexto1, finalSexto);
}

// operator+=(Coord& Y)
TEST(CoordenadaTest, operatorPlusEqual) {
    // Nulo
    Coord primero1 = Coord(4,3);
    Coord primero2 = Coord(0,0);
    Coord finalPrimero = Coord(4,3);
    // Nulo bis
    Coord segundo1 = Coord(-2,-3);
    Coord segundo2 = Coord(0,0);
    Coord finalSegundo = Coord(-2,-3);
    // Todos positivos
    Coord tercero1 = Coord(4,2);
    Coord tercero2 = Coord(1,3);
    Coord finalTercero = Coord(5,5);
    // Todos negativos
    Coord cuarto1 = Coord(-1,-5);
    Coord cuarto2 = Coord(1,5);
    Coord finalCuarto = Coord(0,0);
    // X positivo, Y negativo
    Coord quinto1 = Coord(3,-7);
    Coord quinto2 = Coord(1,-1);
    Coord finalQuinto = Coord(4,-8);
    // X negativo, Y positivo
    Coord sexto1 = Coord(-3,2);
    Coord sexto2 = Coord(6,-2);
    Coord finalSexto = Coord(3,0);

    primero1 += primero2;
    segundo1 += segundo2;
    tercero1 = tercero2;
    cuarto1 = cuarto2;
    quinto1 = quinto2;
    sexto1 = sexto2;

    // Estan bien los "EXPECT_EQ"? O primero deberia utilizar el comando == de
    // coord y luego poner "EXPECT_TRUE"?
    EXPECT_EQ(primero1, finalPrimero);
    EXPECT_EQ(segundo1, finalSegundo);
    EXPECT_EQ(tercero1, finalTercero);
    EXPECT_EQ(cuarto1, finalCuarto);
    EXPECT_EQ(quinto1, finalQuinto);
    EXPECT_EQ(sexto1, finalSexto);
}

TEST(CoordenadaTest, operatorMinusEqual) {
    // Nulo
    Coord primero1 = Coord(4,3);
    Coord primero2 = Coord(0,0);
    Coord finalPrimero = Coord(4,3);
    // Nulo bis
    Coord segundo1 = Coord(-2,-3);
    Coord segundo2 = Coord(0,0);
    Coord finalSegundo = Coord(-2,-3);
    // Todos positivos
    Coord tercero1 = Coord(4,2);
    Coord tercero2 = Coord(1,3);
    Coord finalTercero = Coord(3,-1);
    // Todos negativos
    Coord cuarto1 = Coord(-1,-5);
    Coord cuarto2 = Coord(1,5);
    Coord finalCuarto = Coord(-2,-10);
    // X positivo, Y negativo
    Coord quinto1 = Coord(3,-7);
    Coord quinto2 = Coord(1,-1);
    Coord finalQuinto = Coord(2,-6);
    // X negativo, Y positivo
    Coord sexto1 = Coord(-3,2);
    Coord sexto2 = Coord(6,-2);
    Coord finalSexto = Coord(-9,4);

    primero1 -= primero2;
    segundo1 -= segundo2;
    tercero1 -= tercero2;
    cuarto1 -= cuarto2;
    quinto1 -= quinto2;
    sexto1 -= sexto2;

    // Estan bien los "EXPECT_EQ"? O primero deberia utilizar el comando == de
    // coord y luego poner "EXPECT_TRUE"?
    EXPECT_EQ(primero1, finalPrimero);
    EXPECT_EQ(segundo1, finalSegundo);
    EXPECT_EQ(tercero1, finalTercero);
    EXPECT_EQ(cuarto1, finalCuarto);
    EXPECT_EQ(quinto1, finalQuinto);
    EXPECT_EQ(sexto1, finalSexto);
}

//operator==(Coord& Y)
TEST(CoordenadaTest, operatorEqualEqual) {
    // Nulo
    Coord primero = Coord(0,0);
    Coord primeroIgual = Coord(0,0);
    Coord primeroDesigualPositivo = Coord(1,2);
    Coord primeroDesigualNegativo = Coord(-1,-2);
    Coord primeroDesigualPosNeg = Coord(1,-2);
    Coord primeroDesigualNegPos = Coord(-1,2);
    // Todos positivos
    Coord segundo = Coord(2,3);
    Coord segundoIgual = Coord(2,3);
    Coord segundoDesigualPositivo = Coord(3,3);
    Coord segundoDesigualNegativo = Coord(-2,-3);
    Coord segundoDesigualPosNeg = Coord(1,-2);
    Coord segundoDesigualNegPos = Coord(-1,2);
    Coord segundoDesigualNulo = Coord(0,0);
    // Todos negativos
    Coord tercero = Coord(-1,-5);
    Coord terceroIgual = Coord(-1,-5);
    Coord terceroDesigualPositivo = Coord(1,5);
    Coord terceroDesigualNegativo = Coord(-3,-10);
    Coord terceroDesigualPosNeg = Coord(6,-5);
    Coord terceroDesigualNegPos = Coord(-1,0);
    Coord terceroDesigualNulo = Coord(0,0);
    // X positivo, Y negativo
    Coord cuarto = Coord(0,-5);
    Coord cuartoIgual = Coord(0,-5);
    Coord cuartoDesigualPositivo = Coord(5,2);
    Coord cuartoDesigualNegativo = Coord(-3,-10);
    Coord cuartoDesigualPosNeg = Coord(6,-2);
    Coord cuartoDesigualNegPos = Coord(-1,0);
    Coord cuartoDesigualNulo = Coord(0,0);
    // X negativo, Y positivo
    Coord quinto = Coord(-1,2);
    Coord quintoIgual = Coord(-1,2);
    Coord quintoDesigualPositivo = Coord(5,3);
    Coord quintoDesigualNegativo = Coord(-3,-10);
    Coord quintoDesigualPosNeg = Coord(6,-2);
    Coord quintoDesigualNegPos = Coord(1,-2);
    Coord quintoDesigualNulo = Coord(0,0);

    // Resultados nulo
    EXPECT_TRUE(primero == primeroIgual);
    EXPECT_FALSE(primero == primeroDesigualPositivo);
    EXPECT_FALSE(primero == primeroDesigualNegativo);
    EXPECT_FALSE(primero == primeroDesigualPosNeg);
    EXPECT_FALSE(primero == primeroDesigualNegPos);
    // Resultados todos positivos
    EXPECT_TRUE(segundo == segundoIgual);
    EXPECT_FALSE(segundo == segundoDesigualPositivo);
    EXPECT_FALSE(segundo == segundoDesigualNegativo);
    EXPECT_FALSE(segundo == segundoDesigualPosNeg);
    EXPECT_FALSE(segundo == segundoDesigualNegPos);
    EXPECT_FALSE(segundo == segundoDesigualNulo);
    // Resultados todos negativos
    EXPECT_TRUE(tercero == terceroIgual);
    EXPECT_FALSE(tercero == terceroDesigualPositivo);
    EXPECT_FALSE(tercero == terceroDesigualNegativo);
    EXPECT_FALSE(tercero == terceroDesigualPosNeg);
    EXPECT_FALSE(tercero == terceroDesigualNegPos);
    EXPECT_FALSE(tercero == terceroDesigualNulo);
    // Resultados X positivo, Y negativo
    EXPECT_TRUE(cuarto == cuartoIgual);
    EXPECT_FALSE(cuarto == cuartoDesigualPositivo);
    EXPECT_FALSE(cuarto == cuartoDesigualNegativo);
    EXPECT_FALSE(cuarto == cuartoDesigualPosNeg);
    EXPECT_FALSE(cuarto == cuartoDesigualNegPos);
    EXPECT_FALSE(cuarto == cuartoDesigualNulo);
    // Resultados X negativo, Y positivo
    EXPECT_TRUE(quinto == quintoIgual);
    EXPECT_FALSE(quinto == quintoDesigualPositivo);
    EXPECT_FALSE(quinto == quintoDesigualNegativo);
    EXPECT_FALSE(quinto == quintoDesigualPosNeg);
    EXPECT_FALSE(quinto == quintoDesigualNegPos);
    EXPECT_FALSE(quinto == quintoDesigualNulo);
}

// operator!=(Coord& Y)
TEST(CoordenadaTest, operatorNotEqual) {
    // Nulo
    Coord primero = Coord(0,0);
    Coord primeroIgual = Coord(0,0);
    Coord primeroDesigualPositivo = Coord(1,2);
    Coord primeroDesigualNegativo = Coord(-1,-2);
    Coord primeroDesigualPosNeg = Coord(1,-2);
    Coord primeroDesigualNegPos = Coord(-1,2);
    // Todos positivos
    Coord segundo = Coord(2,3);
    Coord segundoIgual = Coord(2,3);
    Coord segundoDesigualPositivo = Coord(3,3);
    Coord segundoDesigualNegativo = Coord(-2,-3);
    Coord segundoDesigualPosNeg = Coord(1,-2);
    Coord segundoDesigualNegPos = Coord(-1,2);
    Coord segundoDesigualNulo = Coord(0,0);
    // Todos negativos
    Coord tercero = Coord(-1,-5);
    Coord terceroIgual = Coord(-1,-5);
    Coord terceroDesigualPositivo = Coord(1,5);
    Coord terceroDesigualNegativo = Coord(-3,-10);
    Coord terceroDesigualPosNeg = Coord(6,-5);
    Coord terceroDesigualNegPos = Coord(-1,0);
    Coord terceroDesigualNulo = Coord(0,0);
    // X positivo, Y negativo
    Coord cuarto = Coord(0,-5);
    Coord cuartoIgual = Coord(0,-5);
    Coord cuartoDesigualPositivo = Coord(5,2);
    Coord cuartoDesigualNegativo = Coord(-3,-10);
    Coord cuartoDesigualPosNeg = Coord(6,-2);
    Coord cuartoDesigualNegPos = Coord(-1,0);
    Coord cuartoDesigualNulo = Coord(0,0);
    // X negativo, Y positivo
    Coord quinto = Coord(-1,2);
    Coord quintoIgual = Coord(-1,2);
    Coord quintoDesigualPositivo = Coord(5,3);
    Coord quintoDesigualNegativo = Coord(-3,-10);
    Coord quintoDesigualPosNeg = Coord(6,-2);
    Coord quintoDesigualNegPos = Coord(1,-2);
    Coord quintoDesigualNulo = Coord(0,0);

    // Resultados nulo
    EXPECT_FALSE(primero != primeroIgual);
    EXPECT_TRUE(primero != primeroDesigualPositivo);
    EXPECT_TRUE(primero != primeroDesigualNegativo);
    EXPECT_TRUE(primero != primeroDesigualPosNeg);
    EXPECT_TRUE(primero != primeroDesigualNegPos);
    // Resultados todos positivos
    EXPECT_FALSE(segundo != segundoIgual);
    EXPECT_TRUE(segundo != segundoDesigualPositivo);
    EXPECT_TRUE(segundo != segundoDesigualNegativo);
    EXPECT_TRUE(segundo != segundoDesigualPosNeg);
    EXPECT_TRUE(segundo != segundoDesigualNegPos);
    EXPECT_TRUE(segundo != segundoDesigualNulo);
    // Resultados todos negativos
    EXPECT_FALSE(tercero != terceroIgual);
    EXPECT_TRUE(tercero != terceroDesigualPositivo);
    EXPECT_TRUE(tercero != terceroDesigualNegativo);
    EXPECT_TRUE(tercero != terceroDesigualPosNeg);
    EXPECT_TRUE(tercero != terceroDesigualNegPos);
    EXPECT_TRUE(tercero != terceroDesigualNulo);
    // Resultados X positivo, Y negativo
    EXPECT_FALSE(cuarto != cuartoIgual);
    EXPECT_TRUE(cuarto != cuartoDesigualPositivo);
    EXPECT_TRUE(cuarto != cuartoDesigualNegativo);
    EXPECT_TRUE(cuarto != cuartoDesigualPosNeg);
    EXPECT_TRUE(cuarto != cuartoDesigualNegPos);
    EXPECT_TRUE(cuarto != cuartoDesigualNulo);
    // Resultados X negativo, Y positivo
    EXPECT_FALSE(quinto != quintoIgual);
    EXPECT_TRUE(quinto != quintoDesigualPositivo);
    EXPECT_TRUE(quinto != quintoDesigualNegativo);
    EXPECT_TRUE(quinto != quintoDesigualPosNeg);
    EXPECT_TRUE(quinto != quintoDesigualNegPos);
    EXPECT_TRUE(quinto != quintoDesigualNulo);
}

// toIdx(uint cols)
TEST(CoordenadaTest, toIdxCuadrado) {
    // Mapas 2x2 a 8x8
    for (int k = 2; k < 9; k++) {
        uint actualIdx = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                Coord pos = Coord(j, i);
                uint idxFuncion = pos.toIdx(k);
                // Aca se hace el checkeo
                EXPECT_EQ(idxFuncion, actualIdx);
                actualIdx++;
            }
        }
    }
}

TEST(CoordenadaTest, toIdxRectangular) {
    // Mapas qxk (q < k)
    for (int q = 2; q < 8; q++) {
        for (int k = q+1; k < 9; k++) {
            uint actualIdx = 0;
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < k; j++) {
                    Coord pos = Coord(j, i);
                    uint idxFuncion = pos.toIdx(k);
                    // Aca se hace el checkeo
                    EXPECT_EQ(idxFuncion, actualIdx);
                    actualIdx++;
                }
            }
        }
    }
}

// toMap(uint cols)
TEST(CoordenadaTest, toMapCuadrado) {
    // Mapas 2x2 a 8x8 (mapas de kxk)
    for (int k = 2; k < 9; k++) {
        uint actualCell = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                Coord pos = Coord(j, i);
                ulong mapFuncion = pos.toMap(k);
                ulong expected = (ulong)(actualCell);
                // Aca se hace el checkeo
                EXPECT_EQ(mapFuncion, expected);
                actualCell++;
            }
        }
    }
}

TEST(CoordenadaTest, toMapRectangular) {
    // Mapas qxk (q < k)
    for (int q = 2; q < 8; q++) {
        for (int k = q+1; k < 9; k++) {
            uint actualCell = 1;
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < k; j++) {
                    Coord pos = Coord(j, i);
                    uint mapFuncion = pos.toMap(k);
                    ulong expected = (ulong)(actualCell);
                    // Aca se hace el checkeo
                    EXPECT_EQ(mapFuncion, expected);
                    actualCell++;
                }
            }
        }
    }
}

// Tour Counter
// countTours()
TEST(TourCounterTest, countTours1) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(0,3), Coord(3,2), Coord(2,1));
    EXPECT_EQ(tc.countTours(), 2);
}

TEST(TourCounterTest, countTours2) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(1,2), Coord(2,3), Coord(2,1));
    EXPECT_EQ(tc.countTours(), 1);
}

TEST(TourCounterTest, countTours3) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(1,2), Coord(2,3), Coord(2,1));
    EXPECT_EQ(tc.countTours(), 1);
}

TEST(TourCounterTest, countTours4) {
    // Paso 4, Paso 9, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(2,1), Coord(3,3), Coord(1,2));
    EXPECT_EQ(tc.countTours(), 0);
}

TEST(TourCounterTest, countTours5) {
    // Paso 3, Paso 6, Paso 9
    TourCounter tc;
    tc.inputTests(3,4, Coord(0,2), Coord(3,2), Coord(2,0));
    EXPECT_EQ(tc.countTours(), 1);
}

TEST(TourCounterTest, countTours6) {
    // Paso 3, Paso 6, Paso 9
    TourCounter tc;
    tc.inputTests(3,4, Coord(0,2), Coord(2,1), Coord(3,1));
    EXPECT_EQ(tc.countTours(), 1);
}

// tryTo(Coord& to)
TEST(TourCounterTest, tryTo1) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(1,2), Coord(2,3), Coord(2,1));
    EXPECT_EQ(tc.tryTo(LEFT), 0);
}

TEST(TourCounterTest, tryTo2) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(1,2), Coord(2,3), Coord(2,1));
    EXPECT_EQ(tc.tryTo(RIGHT), 0);
}

TEST(TourCounterTest, tryTo3) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(1,2), Coord(2,3), Coord(2,1));
    EXPECT_TRUE(tc.tryTo(UP));
}

TEST(TourCounterTest, tryTo4) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(1,2), Coord(2,3), Coord(2,1));
    EXPECT_EQ(tc.tryTo(DOWN), 0);
}

TEST(TourCounterTest, tryTo5) {
    // Paso 3, Paso 6, Paso 9
    TourCounter tc;
    tc.inputTests(3,4, Coord(0,2), Coord(3,2), Coord(2,0));
    EXPECT_EQ(tc.tryTo(UP), 1);
}

TEST(TourCounterTest, tryTo6) {
    // Paso 3, Paso 6, Paso 9
    TourCounter tc;
    tc.inputTests(3,4, Coord(0,2), Coord(3,2), Coord(2,0));
    EXPECT_EQ(tc.tryTo(DOWN), 0);
}

TEST(TourCounterTest, tryTo7) {
    // Paso 3, Paso 6, Paso 9
    TourCounter tc;
    tc.inputTests(3,4, Coord(0,2), Coord(3,2), Coord(2,0));
    EXPECT_EQ(tc.tryTo(LEFT), 0);
}

TEST(TourCounterTest, tryTo8) {
    // Paso 3, Paso 6, Paso 9
    TourCounter tc;
    tc.inputTests(3,4, Coord(0,2), Coord(3,2), Coord(2,0));
    EXPECT_EQ(tc.tryTo(RIGHT), 0);
}

TEST(TourCounterTest, tryTo9) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(0,3), Coord(3,2), Coord(2,1));
    EXPECT_EQ(tc.tryTo(UP), 2);
}

TEST(TourCounterTest, tryTo10) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(0,3), Coord(3,2), Coord(2,1));
    EXPECT_EQ(tc.tryTo(DOWN), 0);
}

TEST(TourCounterTest, tryTo11) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(0,3), Coord(3,2), Coord(2,1));
    EXPECT_EQ(tc.tryTo(LEFT), 0);
}

TEST(TourCounterTest, tryTo12) {
    // Paso 4, Paso 8, Paso 12
    TourCounter tc;
    tc.inputTests(4,4, Coord(0,3), Coord(3,2), Coord(2,1));
    EXPECT_EQ(tc.tryTo(RIGHT), 0);
}

/* int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} */
