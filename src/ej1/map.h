#pragma once

#include "coord.h"
#include "utils.h"

struct Map {
  Map(const uint _rows = 0, const uint _cols = 0);

  void setAt(const struct Coord& pos, const bool val);
  bool getAt(const struct Coord& pos) const;

  bool inRange(const struct Coord& pos) const;
  bool atWall(const struct Coord& pos) const;
  bool atCorner(const struct Coord& pos) const;
  bool isBlocked(const struct Coord& pos) const;
  bool willSplit(const struct Coord& pos) const;
  bool check(const struct Coord& pos) const;
  
  ulong hash;
  uint rows, cols;
};
