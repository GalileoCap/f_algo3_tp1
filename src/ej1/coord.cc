#include "coord.h"

Coord::Coord(const int x, const int y) : _x(x), _y(y) {}

struct Coord Coord::operator-() const { //A: Negative
  return Coord(-_x, -_y);
}

struct Coord Coord::operator+(const struct Coord& Y) const { //A: Addition
  return Coord(_x + Y._x, _y + Y._y);
}

struct Coord& Coord::operator+=(const struct Coord& Y) {
  _x += Y._x;
  _y += Y._y;
  return *this;
}

bool Coord::operator==(const struct Coord& Y) const {
  return _x == Y._x && _y == Y._y;
}
