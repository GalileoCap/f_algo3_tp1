#pragma once

#include "map.h"
#include "coord.h"
#include "utils.h"

struct TourCounter {
  bool input(); //U: Reads the map's dimensions and check-ins from stdin and resets
  ulong countTours(); 

  inline ulong tryTo(const struct Coord& to); //U: Tries moving to one side

  inline bool checkChecks() const; //U: Is in time for the check-ins
  inline bool check() const; //U: It's in a valid state

  Map _map;
  std::array<std::pair<struct Coord, int>, N_CHECKINS + 2> _checkIns; //U: Check-ins in order, including START_POS and END_POS
  struct Coord _pos; //U: Current position of the robot
  uint _step;
#ifdef DEBUG
  ulong _nodes;
#endif
};
