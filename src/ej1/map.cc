#include "map.h"
#include "utils.h"

Map::Map(const uint _rows, const uint _cols) : hash(0), rows(_rows), cols(_cols) {}

// Seteo la posicion con el valor de 'val' (true o false)
void Map::setAt(const struct Coord& pos, const bool val) {
  if (val) hash |= pos.toMap(cols);
  else hash &= ~pos.toMap(cols);
}

// Si me tira false, no pase por esa casilla. Si me tira true si.
bool Map::getAt(const struct Coord& pos) const {
  return bool(hash & pos.toMap(cols));
}

// Si estoy dentro de los limites del mapa
bool Map::inRange(const struct Coord& pos) const {
  return pos.x >= 0 && pos.x < cols && pos.y >= 0 && pos.y < rows;
}

// Si puedo ir a esa casilla
bool Map::canGo(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos);
}

// Cuantos de mis vecinos no visite
uint Map::freeNeighbors(const struct Coord& pos) const {
  return (
    (inRange(pos + LEFT) && getAt(pos + LEFT)) +
    (inRange(pos + RIGHT) && getAt(pos + RIGHT)) +
    (inRange(pos + UP) && getAt(pos + UP)) +
    (inRange(pos + DOWN) && getAt(pos + DOWN))
    );
}

bool Map::isBlocked(const struct Coord& pos) const {
  bool res = !(pos == END_POS); //A: The END_POS can't be blocked //TODO: Only on the last step
  if (res && inRange(pos + LEFT)) res &= getAt(pos + LEFT);
  if (res && inRange(pos + RIGHT)) res &= getAt(pos + RIGHT);
  if (res && inRange(pos + UP)) res &= getAt(pos + UP);
  if (res && inRange(pos + DOWN)) res &= getAt(pos + DOWN);
  return res;
}

bool Map::willSplit(const struct Coord& pos) const { //U: Setting this position will split the map in two
  bool res = false;
  if (!res && !canGo(pos + LEFT) && !canGo(pos + RIGHT)) res |= canGo(pos + UP) && canGo(pos + DOWN);
  if (!res && !canGo(pos + UP) && !canGo(pos + DOWN)) res |= canGo(pos + LEFT) && canGo(pos + RIGHT);
  return res;
}

bool Map::check(const struct Coord& pos) const {
  return inRange(pos) && !getAt(pos) && !willSplit(pos) && !isBlocked(pos); //TODO: Will block
}
