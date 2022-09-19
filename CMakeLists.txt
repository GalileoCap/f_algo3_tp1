cmake_minimum_required(VERSION 3.5)
project(TP1)

set(CMAKE_CXX_STANDARD 11)

# Algunos flags para pasar al compilador (gnu++11 en vez de c++11 para que sea cross-plat)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

# Dependencia de Google Test
SET(BUILD_GMOCK OFF)
SET(BUILD_GTEST ON)
add_library(gtest STATIC
        tests/gtest-1.8.1/gtest-all.cc
        src/ej1/coord.cc
        src/ej1/coord.h
        src/ej1/map.cc
        src/ej1/map.h
        src/ej1/tourCounter.cc
        src/ej1/tourCounter.h
        src/ej1/utils.h
        src/ej2/sprinkler.cc
        src/ej2/sprinkler.h
        src/ej2/utils.h
        src/ej3/sprinkler.cc
        src/ej3/sprinkler.h
        src/ej3/utils.h
        # ej1/main.cc
        )

add_library(gtest_main STATIC
        tests/gtest-1.8.1/gtest_main.cc
        src/ej1/coord.cc
        src/ej1/coord.h
        src/ej1/map.cc
        src/ej1/map.h
        src/ej1/tourCounter.cc
        src/ej1/tourCounter.h
        src/ej1/utils.h
        src/ej2/sprinkler.cc
        src/ej2/sprinkler.h
        src/ej2/utils.h
        src/ej3/sprinkler.cc
        src/ej3/sprinkler.h
        src/ej3/utils.h
        # ej1/main.cc
        )

# Leemos todos los archivos fuentes en ./src
file(GLOB SOURCE_FILES src/*.cpp src/*.h src/*.hpp)

add_executable(correrTests ${SOURCE_FILES}
        tests/testmain.cpp
        tests/testej1.cpp
        tests/testej2.cpp
        tests/testej3.cpp
        src/ej1/coord.cc
        src/ej1/coord.h
        src/ej1/map.cc
        src/ej1/map.h
        src/ej1/tourCounter.cc
        src/ej1/tourCounter.h
        src/ej1/utils.h
        src/ej2/sprinkler.cc
        src/ej2/sprinkler.h
        src/ej2/utils.h
        src/ej3/sprinkler.cc
        src/ej3/sprinkler.h
        src/ej3/utils.h
        # ej1/main.cc
        )

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)

# Test suites a ejecutar
add_test(correrTests ej1-test)
add_test(correrTests ej2-test)
add_test(correrTests ej3-test)