#include "map.h"
#include "utils.h"

Map::Map(const uint _rows, const uint _cols) : map(_rows, std::vector<bool> (_cols, false)), rows(_rows), cols(_cols) {}

void Map::setAt(const struct Coord& pos, const bool val) {
  map[pos._y][pos._x] = val;
}

bool Map::getAt(const struct Coord& pos) const {
  return map[pos._y][pos._x];
}

bool Map::inRange(const struct Coord& pos) const {
  return pos._x >= 0 && pos._x < cols && pos._y >= 0 && pos._y < rows;
}

bool Map::isBlocked(const struct Coord& pos) const {
  bool res = !(pos == END_POS); //A: Ignore the END_POS //TODO: Only on the last step
  if (inRange(pos + LEFT)) res &= getAt(pos + LEFT);
  if (inRange(pos + RIGHT)) res &= getAt(pos + RIGHT);
  if (inRange(pos + UP)) res &= getAt(pos + UP);
  if (inRange(pos + DOWN)) res &= getAt(pos + DOWN);
  if (res) res &= !getAt(pos);
  return res;
}

bool Map::check(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos) && !isBlocked(pos);
}
