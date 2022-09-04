#include "map.h"
#include "utils.h"
#include <array>

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
  bool res = !getAt(pos);
  res &= !(pos == END_POS); //A: Ignore the END_POS //TODO: Only on the last step
  if (res && inRange(pos + LEFT)) res &= getAt(pos + LEFT);
  if (res && inRange(pos + RIGHT)) res &= getAt(pos + RIGHT);
  if (res && inRange(pos + UP)) res &= getAt(pos + UP);
  if (res && inRange(pos + DOWN)) res &= getAt(pos + DOWN);
  return res;
}

bool Map::atWall(const struct Coord& pos) const {
  return !(inRange(pos + LEFT) && inRange(pos + RIGHT)) || !(inRange(pos + UP) && inRange(pos + DOWN));
}

bool Map::atCorner(const struct Coord& pos) const {
  return !(inRange(pos + LEFT) && inRange(pos + RIGHT)) && !(inRange(pos + UP) && inRange(pos + DOWN));
}

bool Map::willSplit(const struct Coord& pos) const {
  bool res = atWall(pos) && !atCorner(pos);
  if (res && inRange(pos + LEFT) && inRange(pos + RIGHT)) res &= !getAt(pos + LEFT) && !getAt(pos + RIGHT);
  if (res && inRange(pos + UP) && inRange(pos + DOWN)) res &= !getAt(pos + UP) && !getAt(pos + DOWN);
  return res;
}

bool Map::check(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos) && !willSplit(pos) && !isBlocked(pos);
}
