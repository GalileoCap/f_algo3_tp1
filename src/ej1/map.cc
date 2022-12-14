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

inline bool Map::inRange(const struct Coord& pos) const {
  return pos.x >= 0 && pos.x < cols && pos.y >= 0 && pos.y < rows;
}

inline bool Map::canGo(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos);
}

inline uint Map::freeNeighbors(const struct Coord& pos) const {
  return (
    (inRange(pos + LEFT) && getAt(pos + LEFT)) +
    (inRange(pos + RIGHT) && getAt(pos + RIGHT)) +
    (inRange(pos + UP) && getAt(pos + UP)) +
    (inRange(pos + DOWN) && getAt(pos + DOWN))
    );
}

inline bool Map::isBlocked(const struct Coord& pos) const {
  bool res = !(pos == END_POS); //A: The END_POS can't be blocked //TODO: Only on the last step
  if (res && inRange(pos + LEFT)) res &= getAt(pos + LEFT);
  if (res && inRange(pos + RIGHT)) res &= getAt(pos + RIGHT);
  if (res && inRange(pos + UP)) res &= getAt(pos + UP);
  if (res && inRange(pos + DOWN)) res &= getAt(pos + DOWN);
  return res;
}

inline bool Map::willSplit(const struct Coord& pos) const { //U: Setting this position will split the map in two
  bool res = false;
  if (!res && !canGo(pos + LEFT) && !canGo(pos + RIGHT)) res |= canGo(pos + UP) && canGo(pos + DOWN);
  if (!res && !canGo(pos + UP) && !canGo(pos + DOWN)) res |= canGo(pos + LEFT) && canGo(pos + RIGHT);
  return res;
}

bool Map::check(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos) && !willSplit(pos) && !isBlocked(pos); //TODO: Will block
}
