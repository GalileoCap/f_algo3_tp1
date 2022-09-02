#include "map.h"
#include "utils.h"

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

bool Map::isBlocked(const struct Coord& pos) const {
  bool res = !getAt(pos) && !(pos == END_POS);
  res &= inRange(pos + LEFT) && getAt(pos + LEFT);
  res &= inRange(pos + RIGHT) && getAt(pos + RIGHT);
  res &= inRange(pos + UP) && getAt(pos + UP);
  res &= inRange(pos + DOWN) && getAt(pos + DOWN);
  return res;
}

bool Map::check(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos) && !isBlocked(pos);
}
