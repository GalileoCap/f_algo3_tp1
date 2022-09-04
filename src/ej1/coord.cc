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

uint Coord::toIdx(const uint cols) const {
  return x + cols * y;
}

ulong Coord::toMap(const uint cols) const {
  ulong res = 1;
  return (res << (ulong)toIdx(cols));
}
