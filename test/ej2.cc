#include "gtest-1.8.1/gtest.h"
#include "../src/ej2/sprinkler.h"

// TESTS GLOBALES
TEST(GameTest2, solve_Consigna1) {
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

    EXPECT_EQ(sprinklers.solve(), 4);
}

TEST(GameTest2, solve_Consigna2) {
    // Segundo ejemplo
    struct SprinklerList sprinklers(10, 1);

    sprinklers.emplace(5, 3);
    sprinklers.emplace(3, 9);
    sprinklers.emplace(1, 6);
    sprinklers.emplace(2, 1);
    sprinklers.emplace(3, 5);
    sprinklers.emplace(2, 9);

    EXPECT_EQ(sprinklers.solve(), 2);
}

TEST(GameTest2, solve_Consigna3) {
    // Tercer ejemplo
    struct SprinklerList sprinklers(10, 1);

    sprinklers.emplace(3, 5);
    sprinklers.emplace(1, 1);
    sprinklers.emplace(1, 9);

    EXPECT_EQ(sprinklers.solve(), -1);
}

TEST(GameTest2, solve_Consigna4) {
    // Cuarto ejemplo (slide)
    struct SprinklerList sprinklers(14, 4);

    sprinklers.emplace(3, 3);
    sprinklers.emplace(2, 5);
    sprinklers.emplace(3, 7);
    sprinklers.emplace(2, 9);
    sprinklers.emplace(3, 12);

    //EXPECT_EQ(sprinklers.solve(), 3); //NOTA: El ejemplo de los slides está mal
    EXPECT_EQ(sprinklers.solve(), -1); 
}

TEST(GameTest2, solve_LongitudCero1) {
    // l == 0 (posiciones invalidas)
    struct SprinklerList sprinklers(0, 2);
    sprinklers.emplace(3, 5);
    sprinklers.emplace(1, 4);
    sprinklers.emplace(2, 1);
    sprinklers.emplace(2, 7);
    sprinklers.emplace(4, 19);

    EXPECT_EQ(sprinklers.solve(), 0);
}

TEST(GameTest2, solve_LongitudCero2) {
    // l == 0 (posiciones validas)
    struct SprinklerList sprinklers(0, 3);
    sprinklers.emplace(4, 0);
    sprinklers.emplace(1, 0);
    sprinklers.emplace(2, 0);

    EXPECT_EQ(sprinklers.solve(), 0);
}

TEST(GameTest2, solve_LongitudCero3) {
    // l == 0 (posicion valida e invalida)
    struct SprinklerList sprinklers(0, 7);
    sprinklers.emplace(3, -2);
    sprinklers.emplace(10, 0);

    EXPECT_EQ(sprinklers.solve(), 0);
}

TEST(GameTest2, solve_DiametroWidthORSumaDiametrosLength1) {
    // Diametro de sprinklers == width
    struct SprinklerList sprinklers(3, 8);
    sprinklers.emplace(4, 0);
    sprinklers.emplace(4, 1);
    sprinklers.emplace(4, 2);

    EXPECT_EQ(sprinklers.solve(), -1);
}

TEST(GameTest2, solve_DiametroWidthORSumaDiametrosLength2) {
    // Suma diametro de sprinklers == length
    struct SprinklerList sprinklers(16, 1);
    sprinklers.emplace(2, 2);
    sprinklers.emplace(2, 6);
    sprinklers.emplace(2, 10);
    sprinklers.emplace(2, 14);

    EXPECT_EQ(sprinklers.solve(), -1);
}

TEST(GameTest2, solve_DiametroWidthORSumaDiametrosLength3) {
    // Suma diametro de sprinklers == length y diametro == width
    struct SprinklerList sprinklers(6, 2);
    sprinklers.emplace(1, 1);
    sprinklers.emplace(1, 3);
    sprinklers.emplace(1, 5);

    EXPECT_EQ(sprinklers.solve(), -1);
}

TEST(GameTest2, solve_SolucionPositiva1) {
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

    EXPECT_EQ(sprinklers.solve(), 6);
}

TEST(GameTest2, solve_SolucionPositiva2) {
    // Sprinkler encima de otro (uno resuelve, otro no)
    struct SprinklerList sprinklers(8, 2);

    sprinklers.emplace(5, 1); // mas grande, si resuelve
    sprinklers.emplace(3, 6);
    sprinklers.emplace(2, 1); // mas chico en mismo lugar que el primero (no resuelve)

    EXPECT_EQ(sprinklers.solve(), 2);
}

TEST(GameTest2, solve_SolucionPositiva3) {
    // Resuelve pero se quieren cargar sprinklers con datos invalidos
    struct SprinklerList sprinklers(8, 2);

    sprinklers.emplace(5, 1);
    sprinklers.emplace(3, 6);
    sprinklers.emplace(-2, 0);
    sprinklers.emplace(1, 10);
    sprinklers.emplace(-4, 18);

    EXPECT_EQ(sprinklers.solve(), 2);
}

//TEST(GameTest2, solve_NMayorA10000) { //NOTA: n > 10000 está indefinido, porque rompe contrato
    //struct SprinklerList sprinklers(1, 2);
//
    //for(int i = 0; i <= 10001; i++) {
        //sprinklers.emplace(3, 1);
    //}
//
    //EXPECT_EQ(sprinklers.solve(), -1);
//}

// TESTS UNITARIOS
// SprinklerList(const ulong _l, const ulong _w);
TEST(SprinklerListTest2, SprinklerList_EnterosPositivos) {
    // Enteros > 0
    struct SprinklerList sprinklers(8, 2);

    EXPECT_EQ(sprinklers.l, 8);
    EXPECT_EQ(sprinklers.w, 2);
    EXPECT_TRUE(sprinklers.queue.empty());
}

TEST(SprinklerListTest2, SprinklerList_Longitud0) {
    // l = 0
    struct SprinklerList sprinklers(0, 5);

    EXPECT_EQ(sprinklers.l, 0);
    EXPECT_EQ(sprinklers.w, 5);
    EXPECT_TRUE(sprinklers.queue.empty());
}

TEST(SprinklerListTest2, SprinklerList_Width0) {
    // w = 0
    struct SprinklerList sprinklers(7, 0);

    EXPECT_EQ(sprinklers.l, 7);
    EXPECT_EQ(sprinklers.w, 0);
    EXPECT_TRUE(sprinklers.queue.empty());
}

TEST(SprinklerListTest2, SprinklerList_LongitudYWidth0) {
    // l = w = 0
    struct SprinklerList sprinklers(0, 0);

    EXPECT_EQ(sprinklers.l, 0);
    EXPECT_EQ(sprinklers.w, 0);
    EXPECT_TRUE(sprinklers.queue.empty());
}

TEST(SprinklerListTest2, SprinklerList_LongitudMenor0) {
    // l < 0
    struct SprinklerList sprinklers(-10, 80);

    EXPECT_EQ(sprinklers.l, -10);
    EXPECT_EQ(sprinklers.w, 80);
    EXPECT_TRUE(sprinklers.queue.empty());
}

TEST(SprinklerListTest2, SprinklerList_WidthMenor0) {
    // w < 0
    struct SprinklerList sprinklers(310, -82313);

    EXPECT_EQ(sprinklers.l, 310);
    EXPECT_EQ(sprinklers.w, -82313);
    EXPECT_TRUE(sprinklers.queue.empty());
}

TEST(SprinklerListTest2, SprinklerList_NegativoNegativo) {
    // Negativo-Negativo
    struct SprinklerList sprinklers(-111, -764);

    EXPECT_EQ(sprinklers.l, -111);
    EXPECT_EQ(sprinklers.w, -764);
    EXPECT_TRUE(sprinklers.queue.empty());
}

// emplace(const ulong r, const ulong pos);
TEST(SprinklerListTest2, emplace_EnRango1) {
    struct SprinklerList sprinklers1(10, 2);
    for(int i = 0; i <= 10; i++) {
        struct SprinklerList::Sprinkler sprinkler(1,i,sprinklers1.w);
        sprinklers1.emplace(1,i);
        EXPECT_TRUE((sprinklers1.queue.top().leftLim == sprinkler.leftLim) && (sprinklers1.queue.top().rightLim == sprinkler.rightLim));
    }
}

TEST(SprinklerListTest2, emplace_EnRango2) {
    struct SprinklerList sprinklers2(10, 2);
    for(int i = 0; i <= 10; i++) {
        struct SprinklerList::Sprinkler sprinkler(1+i,i,sprinklers2.w);
        sprinklers2.emplace(1+i,i);
        EXPECT_TRUE((sprinklers2.queue.top().leftLim == sprinkler.leftLim) && (sprinklers2.queue.top().rightLim == sprinkler.rightLim));
    }
}

TEST(SprinklerListTest2, emplace_EnRango3) {
    struct SprinklerList sprinklers3(10, 2);
    for(int i = 10; i >= 0; i--) {
        sprinklers3.emplace(1+i,i);
    }
    for(int i = 0; i <= 10; i++) {
        struct SprinklerList::Sprinkler sprinkler(11-i,10-i,sprinklers3.w);
        EXPECT_TRUE((sprinklers3.queue.top().leftLim == sprinkler.leftLim) && (sprinklers3.queue.top().rightLim == sprinkler.rightLim));
        sprinklers3.queue.pop();
    }
}

TEST(SprinklerListTest2, emplace_MismaPosicion1) {
    // Sprinklers encimados en la misma posicion
    // Ejemplo 1 (mas chico a mas grande)
    struct SprinklerList sprinklers4(4, 2);
    for(int i = 0; i <= 3; i++) {
        struct SprinklerList::Sprinkler sprinkler(1+i,2,sprinklers4.w);
        sprinklers4.emplace(1+i,2);
        EXPECT_TRUE((sprinklers4.queue.top().leftLim == sprinkler.leftLim) && (sprinklers4.queue.top().rightLim == sprinkler.rightLim));
    }
}

TEST(SprinklerListTest2, emplace_MismaPosicion2) {
    // Sprinklers encimados en la misma posicion
    // Ejemplo 2 (mas grande a mas chico)
    struct SprinklerList sprinklers5(4, 2);
    for(int i = 0; i <= 3; i++) {
        struct SprinklerList::Sprinkler sprinkler(4-i,2,sprinklers5.w);
        sprinklers5.emplace(4-i,2);
    }

    for(int i = 0; i <= 3; i++) {
        struct SprinklerList::Sprinkler sprinkler(4-i,2,sprinklers5.w);
        EXPECT_TRUE((sprinklers5.queue.top().leftLim == sprinkler.leftLim) && (sprinklers5.queue.top().rightLim == sprinkler.rightLim));
        sprinklers5.queue.pop();
    }
}

TEST(SprinklerListTest2, emplace_MismaPosicion3) {
    // Sprinklers encimados en la misma posicion
    // Ejemplo 3 (todos iguales)
    struct SprinklerList sprinklers6(7, 3);
    for(int i = 0; i <= 3; i++) {
        sprinklers6.emplace(1,3);
    }

    int queueSize = sprinklers6.queue.size();
    EXPECT_EQ(queueSize, 4);

    for(int i = 0; i <= 3; i++) {
        struct SprinklerList::Sprinkler sprinkler(1,3,sprinklers6.w);
        if(sprinklers6.queue.size() > 0) {
            EXPECT_TRUE((sprinklers6.queue.top().leftLim == sprinkler.leftLim) && (sprinklers6.queue.top().rightLim == sprinkler.rightLim));
            sprinklers6.queue.pop();
        }
    }
}

TEST(SprinklerListTest2, emplace_LongitudPrincipioOFin) {
    // Sprinklers en l = 0 o l = |l|
    struct SprinklerList sprinklers7(5, 1);
    sprinklers7.emplace(1,0);
    sprinklers7.emplace(1,5);
    EXPECT_TRUE(sprinklers7.queue.size() == 2);
}

TEST(SprinklerListTest2, emplace_FueraDeRango1) {
    // Sprinklers fuera de rango (l y w positivos)
    struct SprinklerList sprinklers8(8, 2);
    sprinklers8.emplace(1,12);
    sprinklers8.emplace(1,20);
    EXPECT_TRUE(sprinklers8.queue.size() == 0);
}

TEST(SprinklerListTest2, emplace_FueraDeRango2) {
    // Sprinklers fuera de rango (pos negativa)
    struct SprinklerList sprinklers9(3, 4);
    sprinklers9.emplace(4,-8);
    sprinklers9.emplace(4,-10);
    EXPECT_TRUE(sprinklers9.queue.size() == 0);
}

TEST(SprinklerListTest2, emplace_FueraDeRango3) {
    // Sprinklers fuera de rango (r negativo)
    struct SprinklerList sprinklers10(7, 4);
    sprinklers10.emplace(-2,2);
    sprinklers10.emplace(-6,1);
    EXPECT_TRUE(sprinklers10.queue.size() == 0);
}

// Sprinkler(const ulong _r, const ulong _pos, const ulong w);
TEST(SprinklerTest2, Sprinkler_DiametroIgualWidth) {
    // 2r == w
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler sprinkler1(5,3,list1.w);
    double corte = (double)std::sqrt((double)(25) - (double)(6/4));
    EXPECT_TRUE(sprinkler1.valid);
    EXPECT_EQ(sprinkler1.leftLim, (double) 3 - corte);
    EXPECT_EQ(sprinkler1.rightLim, (double) 3 + corte);
}

TEST(SprinklerTest2, Sprinkler_DiametroMayorALongitud) {
    // 2r > l
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler sprinkler2(8,2,list1.w);
    double corte = (double)std::sqrt((double)(64) - (double)(4/4));
    EXPECT_TRUE(sprinkler2.valid);
    EXPECT_EQ(sprinkler2.leftLim, (double) 2 - corte);
    EXPECT_EQ(sprinkler2.rightLim, (double) 2 + corte);
}

TEST(SprinklerTest2, Sprinkler_EntreElJardin) {
    // entre el jardin
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler sprinkler3(2,1,list1.w);
    double corte = (double)std::sqrt((double)(4) - (double)(1/4));
    EXPECT_TRUE(sprinkler3.valid);
    EXPECT_EQ(sprinkler3.leftLim, (double) 1 - corte);
    EXPECT_EQ(sprinkler3.rightLim, (double) 1 + corte);
}

TEST(SprinklerTest2, Sprinkler_PosicionMenorA0) {
    // pos < 0
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler sprinkler4(2,-4,list1.w);
    EXPECT_FALSE(sprinkler4.valid);
}

TEST(SprinklerTest2, Sprinkler_PosicionMayorALongitud) {
    // pos > l
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler sprinkler5(2,47,list1.w);
    EXPECT_FALSE(sprinkler5.valid);
}

TEST(SprinklerTest2, Sprinkler_DiametroMenorAWidth) {
    // 2r < w
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler sprinkler6(0,6,list1.w);
    EXPECT_FALSE(sprinkler6.valid);
}

// operator<(const struct Sprinkler& s1);
TEST(SprinklerTest2, operatorMenor_MismaPosicionMismoR) {
    // misma posicion, mismo r
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler primero1(3,5,list1.w);
    struct SprinklerList::Sprinkler primero2(3,5,list1.w);
    EXPECT_FALSE(primero1 < primero2);
    EXPECT_FALSE(primero2 < primero1);
}

TEST(SprinklerTest2, operatorMenor_MismaPosicionDistintoR) {
    // misma posicion, distinto r
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler segundo1(2,4,list1.w);
    struct SprinklerList::Sprinkler segundo2(1,4,list1.w);
    EXPECT_FALSE(segundo1 < segundo2);
    EXPECT_TRUE(segundo2 < segundo1);
}

TEST(SprinklerTest2, operatorMenor_IzqMenorRDerMayorR) {
    // menor r, con pos mas cerca de inicio, mayor r, con pos mas lejos de inicio
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler tercero1(1,1,list1.w);
    struct SprinklerList::Sprinkler tercero2(6,3,list1.w);
    EXPECT_FALSE(tercero2 < tercero1);
    EXPECT_TRUE(tercero1 < tercero2);
}

TEST(SprinklerTest2, operatorMenosr_LeftLimNegativo) {
    // leftlim negativo
    struct SprinklerList list1(10,2);
    struct SprinklerList::Sprinkler cuarto1(8,1,list1.w);
    struct SprinklerList::Sprinkler cuarto2(6,3,list1.w);
    EXPECT_FALSE(cuarto1 < cuarto2);
    EXPECT_TRUE(cuarto2 < cuarto1);
}
