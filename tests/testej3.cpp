#include "gtest-1.8.1/gtest.h"
#include "../src/ej3/sprinkler.h"

// TESTS GLOBALES
TEST(GameTest3, solve_Consigna1) {
    // Primer ejemplo
    struct pricedSprinklerList sprinklers(11, 20, 2);

    sprinklers.emplace(3, 5, 1);
    sprinklers.emplace(1, 4, 1);
    sprinklers.emplace(2, 1, 1);
    sprinklers.emplace(2, 7, 2);
    sprinklers.emplace(2, 10, 1);
    sprinklers.emplace(3, 13, 2);
    sprinklers.emplace(2, 16, 1);
    sprinklers.emplace(4, 19, 3);
    sprinklers.emplace(5, 3, 5);
    sprinklers.emplace(2, 9, 2);
    sprinklers.emplace(2, 19, 1);

    EXPECT_EQ(sprinklers.solve(), 8);
}

TEST(GameTest3, solve_Consigna2) {
    // Segundo ejemplo
    struct pricedSprinklerList sprinklers(6, 10, 1);

    sprinklers.emplace(5, 3, 4);
    sprinklers.emplace(3, 9, 3);
    sprinklers.emplace(1, 6, 1);
    sprinklers.emplace(2, 1, 1);
    sprinklers.emplace(3, 5, 1);
    sprinklers.emplace(2, 9, 2);

    EXPECT_EQ(sprinklers.solve(), 4);
}

TEST(GameTest3, solve_Consigna3) {
    // Tercer ejemplo
    struct pricedSprinklerList sprinklers(3, 10, 1);

    sprinklers.emplace(3, 5, 1);
    sprinklers.emplace(1, 1, 2);
    sprinklers.emplace(1, 9, 1);

    EXPECT_EQ(sprinklers.solve(), -1);
}

TEST(GameTest3, solve_Consigna4) {
    // Cuarto ejemplo (similar al del slide)
    struct pricedSprinklerList sprinklers(5, 14, 4);

    sprinklers.emplace(3, 3, 3);
    sprinklers.emplace(5, 5, 5);
    sprinklers.emplace(3, 7, 3);
    sprinklers.emplace(5, 9, 5);
    sprinklers.emplace(3, 12, 3);

    EXPECT_EQ(sprinklers.solve(), -1);
}

TEST(GameTest3, solve_Longitud0Invalidas) {
    // l == 0 (posiciones invalidas)
    struct pricedSprinklerList sprinklers(5, 0, 2);
    sprinklers.emplace(3, 5, 1);
    sprinklers.emplace(1, 4, 4);
    sprinklers.emplace(2, 1, 5);
    sprinklers.emplace(2, 7, 3);
    sprinklers.emplace(4, 19, 2);

    EXPECT_EQ(sprinklers.solve(), 0);
}

TEST(GameTest3, solve_Longitud0Validas) {
    // l == 0 (posiciones validas)
    struct pricedSprinklerList sprinklers(3, 0, 3);
    sprinklers.emplace(4, 0, 3);
    sprinklers.emplace(1, 0, 6);
    sprinklers.emplace(2, 0, 1);

    EXPECT_EQ(sprinklers.solve(), 0);
}

TEST(GameTest3, solve_Longitud0ValidaEInvalida) {
    // l == 0 (posicion valida e invalida)
    struct pricedSprinklerList sprinklers(2, 0, 7);
    sprinklers.emplace(3, -2, 2);
    sprinklers.emplace(10, 0, 4);

    EXPECT_EQ(sprinklers.solve(), 0);
}

// TESTS UNITARIOS
// SprinklerList(const ulong n, const ulong _l, const ulong _w, );
TEST(SprinklerListTest3, SprinklerList_EnterosPositivos) {
    struct pricedSprinklerList sprinklers(1, 8, 2);

    EXPECT_EQ(sprinklers.l, 8);
    EXPECT_EQ(sprinklers.w, 2);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

TEST(SprinklerListTest3, SprinklerList_Longitud0) {
    struct pricedSprinklerList sprinklers(1, 0, 5);

    EXPECT_EQ(sprinklers.l, 0);
    EXPECT_EQ(sprinklers.w, 5);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

TEST(SprinklerListTest3, SprinklerList_Width0) {
    struct pricedSprinklerList sprinklers(1, 7, 0);

    EXPECT_EQ(sprinklers.l, 7);
    EXPECT_EQ(sprinklers.w, 0);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

TEST(SprinklerListTest3, SprinklerList_LongitudYWidth0) {
    struct pricedSprinklerList sprinklers(1, 0, 0);

    EXPECT_EQ(sprinklers.l, 0);
    EXPECT_EQ(sprinklers.w, 0);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

TEST(SprinklerListTest3, SprinklerList_LongitudNegativa) {
    struct pricedSprinklerList sprinklers(1, -10, 80);

    EXPECT_EQ(sprinklers.l, -10);
    EXPECT_EQ(sprinklers.w, 80);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

TEST(SprinklerListTest3, SprinklerList_WidthNegativa) {
    struct pricedSprinklerList sprinklers(1, 310, -82313);

    EXPECT_EQ(sprinklers.l, 310);
    EXPECT_EQ(sprinklers.w, -82313);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

TEST(SprinklerListTest3, SprinklerList_NegativoNegativo) {
    struct pricedSprinklerList sprinklers(1, -111, -764);

    EXPECT_EQ(sprinklers.l, -111);
    EXPECT_EQ(sprinklers.w, -764);
    EXPECT_TRUE(sprinklers.sprinklers.empty());
}

/*
// emplace(const ulong r, const ulong pos);
TEST(SprinklerListTest3, emplace_EnRango1) {
    struct SprinklerList sprinklers1(10, 2);
    for(int i = 0; i <= 10; i++) {
        struct Sprinkler sprinkler(1,i,1,sprinklers1.w);
        sprinklers1.emplace(1,i);
        EXPECT_TRUE((sprinklers1.queue.top().lefLim == sprinkler.leftLim) && (sprinklers1.queue.top().rightLim == sprinkler.rightLim));
    }
}

TEST(SprinklerListTest3, emplace_EnRango2) {
    struct SprinklerList sprinklers2(10, 2);
    for(int i = 0; i <= 10; i++) {
        sprinklers2.emplace(1+i,i);
        EXPECT_TRUE((sprinklers2.queue.top().lefLim == sprinkler.leftLim) && (sprinklers2.queue.top().rightLim == sprinkler.rightLim));
    }
}

TEST(SprinklerListTest3, emplace_EnRango3) {
    struct SprinklerList sprinklers3(10, 2);
    for(int i = 10; i >= 0; i--) {
        sprinklers3.emplace(1+i,i);
    }
    for(int i = 0; i <= 10; i++) {
        struct Sprinkler sprinkler(11-i,10-i,1,sprinklers3.w);
        EXPECT_TRUE((sprinklers3.queue.top().lefLim == sprinkler.leftLim) && (sprinklers3.queue.top().rightLim == sprinkler.rightLim));
        sprinklers3.queue.pop();
    }
}

TEST(SprinklerListTest3, emplace_MismaPosicion1) {
    // Ejemplo 1 (mas chico a mas grande)
    struct SprinklerList sprinklers4(4, 2);
    for(int i = 0; i <= 3; i++) {
        struct Sprinkler sprinkler(1+i,2,1,sprinklers4.w);
        sprinklers4.emplace(1+i,2);
        EXPECT_TRUE((sprinklers4.queue.top().lefLim == sprinkler.leftLim) && (sprinklers4.queue.top().rightLim == sprinkler.rightLim));
    }
}

TEST(SprinklerListTest3, emplace_MismaPosicion2) {
    // Ejemplo 2 (mas grande a mas chico)
    struct SprinklerList sprinklers5(4, 2);
    for(int i = 0; i <= 3; i++) {
        struct Sprinkler sprinkler(4-i,2,1,sprinklers5.w);
        sprinklers5.emplace(4-i,2);
    }

    for(int i = 0; i <= 3; i++) {
        struct Sprinkler sprinkler(4-i,2,1,sprinklers5.w);
        EXPECT_TRUE((sprinklers5.queue.top().lefLim == sprinkler.leftLim) && (sprinklers5.queue.top().rightLim == sprinkler.rightLim));
        sprinklers5.queue.pop();
    }
}

TEST(SprinklerListTest3, emplace_MismaPosicion3) {
    // Ejemplo 3 (todos iguales)
    struct SprinklerList sprinklers6(7, 3);
    for(int i = 0; i <= 3; i++) {
        sprinklers6.emplace(1,3);
    }

    EXPECT_EQUAL(sprinklers6.queue.size(), 4);

    for(int i = 0; i <= 3; i++) {
        struct Sprinkler sprinkler(1,3,1,sprinklers6.w);
        EXPECT_TRUE((sprinklers6.queue.top().lefLim == sprinkler.leftLim) && (sprinklers6.queue.top().rightLim == sprinkler.rightLim));
        sprinklers6.queue.pop();
    }
}

TEST(SprinklerListTest3, emplace_LongitudPrincipioOFinal) {
    // Sprinklers en l = 0 o l = |l|
    struct SprinklerList sprinklers7(5, 1);
    sprinklers7.emplace(1,0);
    sprinklers7.emplace(1,5);
    EXPECT_TRUE(sprinklers7.queue.size() == 2);
}

TEST(SprinklerListTest3, emplace_FueraDeRango1) {
    // Sprinklers fuera de rango (l y w positivos)
    struct SprinklerList sprinklers8(8, 2);
    sprinklers8.emplace(1,12);
    sprinklers8.emplace(1,20);
    EXPECT_TRUE(sprinklers8.queue.size() == 0);
}

TEST(SprinklerListTest3, emplace_FueraDeRango2) {
    // Sprinklers fuera de rango (pos negativa)
    struct SprinklerList sprinklers9(3, 4);
    sprinklers9.emplace(4,-8);
    sprinklers9.emplace(4,-10);
    EXPECT_TRUE(sprinklers9.queue.size() == 0);
}

TEST(SprinklerListTest3, emplace_FueraDeRango3) {
    // Sprinklers fuera de rango (r negativo)
    struct SprinklerList sprinklers10(7, 4);
    sprinklers10.emplace(-2,2);
    sprinklers10.emplace(-6,1);
    EXPECT_TRUE(sprinklers10.queue.size() == 0);
} */


// Sprinkler(const ulong _r, const ulong _pos, const ulong w);
TEST(SprinklerTest3, Sprinkler_DiametroWidth) {
    // 2r == w
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler sprinkler1(5,3,1,list1.w);
    double corte = (double)std::sqrt((double)(25) - (double)(6/4));
    EXPECT_TRUE(sprinkler1.valid);
    EXPECT_EQ(sprinkler1.leftLim, (double) 3 - corte);
    EXPECT_EQ(sprinkler1.rightLim, (double) 3 + corte);
    EXPECT_EQ(sprinkler1.cost, 1);
}

TEST(SprinklerTest3, Sprinkler_DiametroMayorLongitud) {
    // 2r > l
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler sprinkler2(8,2,1,list1.w);
    double corte = (double)std::sqrt((double)(64) - (double)(4/4));
    EXPECT_TRUE(sprinkler2.valid);
    EXPECT_EQ(sprinkler2.leftLim, (double) 2 - corte);
    EXPECT_EQ(sprinkler2.rightLim, (double) 2 + corte);
    EXPECT_EQ(sprinkler2.cost, 1);
}

TEST(SprinklerTest3, Sprinkler_EntreElJardin) {
    // entre el jardin
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler sprinkler3(2,1,1,list1.w);
    double corte = (double)std::sqrt((double)(4) - (double)(1/4));
    EXPECT_TRUE(sprinkler3.valid);
    EXPECT_EQ(sprinkler3.leftLim, (double) 1 - corte);
    EXPECT_EQ(sprinkler3.rightLim, (double) 1 + corte);
    EXPECT_EQ(sprinkler3.cost, 1);
}

TEST(SprinklerTest3, Sprinkler_PosicionMenorA0) {
    // pos < 0
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler sprinkler4(2,-4,1,list1.w);
    EXPECT_FALSE(sprinkler4.valid);
}

TEST(SprinklerTest3, Sprinkler_PosicionMayorLongitud) {
    // pos > l
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler sprinkler5(2,47,1,list1.w);
    EXPECT_FALSE(sprinkler5.valid);
}

TEST(SprinklerTest3, Sprinkler_DiametroMenorWidth) {
    // 2r < w
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler sprinkler6(0,6,1,list1.w);
    EXPECT_FALSE(sprinkler6.valid);
}

// operator<(const struct Sprinkler& s1);
TEST(SprinklerTest3, operatorMenor_MismaPosMismoR) {
    // misma posicion, mismo r
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler primero1(3,5,1,list1.w);
    struct pricedSprinklerList::Sprinkler primero2(3,5,1,list1.w);
    EXPECT_TRUE(primero1 < primero2);
    EXPECT_TRUE(primero2 < primero1);
}

TEST(SprinklerTest3, operatorMenor_MismaPosDistintoR) {
    // misma posicion, distinto r
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler segundo1(2,4,1,list1.w);
    struct pricedSprinklerList::Sprinkler segundo2(1,4,1,list1.w);
    EXPECT_TRUE(segundo1 < segundo2);
    EXPECT_FALSE(segundo2 < segundo1);
}

TEST(SprinklerTest3, operatorMenor_IzqMenorRDerMayorR) {
    // menor r, con pos mas cerca de inicio, mayor r, con pos mas lejos de inicio
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler tercero1(1,1,1,list1.w);
    struct pricedSprinklerList::Sprinkler tercero2(6,3,1,list1.w);
    EXPECT_TRUE(tercero2 < tercero1);
    EXPECT_FALSE(tercero1 < tercero2);
}

TEST(SprinklerTest3, operatorMenor_LeftLimNegativo) {
    // leftlim negativo
    struct pricedSprinklerList list1(1,10,2);
    struct pricedSprinklerList::Sprinkler cuarto1(8,1,1,list1.w);
    struct pricedSprinklerList::Sprinkler cuarto2(6,3,0,list1.w);
    EXPECT_TRUE(cuarto1 < cuarto2);
    EXPECT_FALSE(cuarto2 < cuarto1);
}

// canFill(const uint i, const uint j);


// isFull(const uint last);
/*TEST(SprinklerTest3, isFull_Longitud0) {
    struct pricedSprinklerList sprinklers(0, 0, 2);
    EXPECT_TRUE(isFull(sprinklers), 5);
    EXPECT_TRUE(isFull(sprinklers), -1);
}*/

TEST(SprinklerTest3, isFull1) {
    struct pricedSprinklerList sprinklers(3,10, 1);
    sprinklers.emplace(3, 5, 1);
    sprinklers.emplace(1, 1, 2);
    sprinklers.emplace(1, 9, 1);
    std::sort(sprinklers.sprinklers.begin(), sprinklers.sprinklers.end());

    EXPECT_FALSE(sprinklers.isFull(0));
    EXPECT_FALSE(sprinklers.isFull(1));
}

TEST(SprinklerTest3, isFull2) {
    struct pricedSprinklerList sprinklers(11, 20, 2);

    sprinklers.emplace(3, 5, 1);
    sprinklers.emplace(1, 4, 1);
    sprinklers.emplace(2, 1, 1);
    sprinklers.emplace(2, 7, 2);
    sprinklers.emplace(2, 10, 1);
    sprinklers.emplace(3, 13, 2);
    sprinklers.emplace(2, 16, 1);
    sprinklers.emplace(4, 19, 3);
    sprinklers.emplace(5, 3, 5);
    sprinklers.emplace(2, 9, 2);
    sprinklers.emplace(2, 19, 1);
    std::sort(sprinklers.sprinklers.begin(), sprinklers.sprinklers.end());

    EXPECT_TRUE(sprinklers.isFull(10));
}
