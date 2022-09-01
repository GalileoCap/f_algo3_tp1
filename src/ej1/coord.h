#pragma once

#include "utils.h"

struct Coord {
  Coord(const int x = 0, const int y = 0);

  struct Coord operator-() const; //A: Negative
  struct Coord operator+(const struct Coord& Y) const;
  struct Coord& operator+=(const struct Coord& Y);
  bool operator==(const struct Coord& Y) const;

  int _x, _y;
};

#define LEFT Coord(-1, 0)
#define RIGHT -LEFT
#define UP Coord(0, 1)
#define DOWN -UP
