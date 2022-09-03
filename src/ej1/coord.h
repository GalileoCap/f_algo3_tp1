#pragma once

#include "utils.h"

struct Coord {
  Coord(const uint _x = 0, const uint _y = 0);

  uint manhattan(const struct Coord& Y) const;

  struct Coord operator-() const; //A: Negative
  struct Coord operator+(const struct Coord& Y) const;
  struct Coord operator-(const struct Coord& Y) const;
  struct Coord& operator+=(const struct Coord& Y);
  struct Coord& operator-=(const struct Coord& Y);
  bool operator==(const struct Coord& Y) const;
  uint toIdx(const uint cols) const;
  ulong toMap(const uint cols) const;

  uint x, y;
};

#define LEFT Coord(-1, 0)
#define RIGHT -LEFT
#define UP Coord(0, 1)
#define DOWN -UP
