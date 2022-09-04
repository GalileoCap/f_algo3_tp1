#pragma once

#include "coord.h"
#include "utils.h"

struct Map {
  Map(const uint _rows = 0, const uint _cols = 0);

  void setAt(const struct Coord& pos, const bool val);
  bool getAt(const struct Coord& pos) const;

  inline bool inRange(const struct Coord& pos) const;
  inline bool atWall(const struct Coord& pos) const;
  inline bool atCorner(const struct Coord& pos) const;
  inline uint freeNeighbors(const struct Coord& pos) const;

  inline bool isBlocked(const struct Coord& pos) const; //U: This position doesn't have an escape
  inline bool willSplit(const struct Coord& pos) const; //U: Setting this position will split the map in two
  bool check(const struct Coord& pos) const;
  
  ulong hash;
  uint rows, cols;
};
