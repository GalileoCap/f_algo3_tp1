#include "map.h"

Map::Map(const uint _rows, const uint _cols) : hash(0), rows(_rows), cols(_cols) {}

void Map::setAt(const struct Coord& pos, const bool val) {
  if (val) hash |= (1 << pos.toUint(cols));
  else hash &= ~(1 << pos.toUint(cols));
}

bool Map::getAt(const struct Coord& pos) const {
  return bool(hash & (1 << pos.toUint(cols)));
}

bool Map::inRange(const struct Coord& pos) const {
  return pos._x >= 0 && pos._x < cols && pos._y >= 0 && pos._y < rows;
}
