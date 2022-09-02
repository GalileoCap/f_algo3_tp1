#pragma once

#include "map.h"
#include "coord.h"
#include "utils.h"

struct TourCounter {
  bool input();
  int countTours();

  inline int tryTo(const struct Coord& to);
  inline bool move(const struct Coord& to);

  inline bool checkIn() const;

  Map _map;
  std::array<std::pair<struct Coord, int>, N_CHECKINS + 1> _checkIns; //U: Check-ins in order
  struct Coord _pos; //U: Current position of the robot
  int _step;
#ifdef DEBUG
  ulong _nodes;
#endif
};
