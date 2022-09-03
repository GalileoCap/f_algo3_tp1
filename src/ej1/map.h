#pragma once

#include "coord.h"
#include "utils.h"

struct Map {
  Map(const uint _rows = 0, const uint _cols = 0);

  void setAt(const struct Coord& pos, const bool val);
  bool getAt(const struct Coord& pos) const;

  bool inRange(const struct Coord& pos) const;
  bool isBlocked(const struct Coord& pos) const;
  bool check(const struct Coord& pos) const;
  
  std::vector<std::vector<bool>> map;
  uint rows, cols;
};
