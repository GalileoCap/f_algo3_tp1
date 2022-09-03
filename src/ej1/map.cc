#include "map.h"
#include "utils.h"

Map::Map(const uint _rows, const uint _cols) : hash(0), rows(_rows), cols(_cols) {}

void Map::setAt(const struct Coord& pos, const bool val) {
  if (val) hash |= pos.toMap(cols);
  else hash &= ~pos.toMap(cols);
}

bool Map::getAt(const struct Coord& pos) const {
  return bool(hash & pos.toMap(cols));
}

bool Map::inRange(const struct Coord& pos) const {
  return pos.x >= 0 && pos.x < cols && pos.y >= 0 && pos.y < rows;
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
