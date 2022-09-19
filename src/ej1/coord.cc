#include "coord.h"

Coord::Coord(const uint _x, const uint _y) : x(_x), y(_y) {}

uint Coord::manhattan(const struct Coord& Y) const { //U: Manhattan distance
  return (x > Y.x ? x - Y.x : Y.x - x) + (y > Y.y ? y - Y.y : Y.y - y); //A: abs(dx) + abs(dy)
}

struct Coord Coord::operator-() const { //A: Negative
  return Coord(-x, -y);
}

struct Coord Coord::operator+(const struct Coord& Y) const {
  return Coord(x + Y.x, y + Y.y);
}

struct Coord Coord::operator-(const struct Coord& Y) const {
  return *this + (-Y);
}

struct Coord& Coord::operator+=(const struct Coord& Y) {
  *this = *this + Y;
  return *this;
}

struct Coord& Coord::operator-=(const struct Coord& Y) {
  *this += -Y;
  return *this;
}

bool Coord::operator==(const struct Coord& Y) const {
  return x == Y.x && y == Y.y;
}

bool Coord::operator!=(const struct Coord& Y) const {
  return !(*this == Y);
}

// La posición (0, 0) te da 0, la (1, 0) te da 1, la (2, 0) 2... la (0, c) te da c
uint Coord::toIdx(const uint cols) const {
  return x + cols * y;
}

// La (0, 0) te da 0000...0001, la (1, 0) 0000...0010, y así
ulong Coord::toMap(const uint cols) const {
  ulong res = 1;
  return (res << (ulong)toIdx(cols));
}

/*
 Comportamiento toMap               Comportamiento toIdx
 ^                                  ^
 |--------> 2c+1 a 3c (binario)     |--------> 2c a 3c-1 (entero)
 |--------> c+1 a 2c  (binario)     |--------> c a 2c-1  (entero)
 |--------> 1 a c     (binario)     |--------> 0 a c-1   (entero)
*/