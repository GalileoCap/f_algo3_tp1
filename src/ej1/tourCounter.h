#pragma once

#include "utils.h"
#include "map.h"

#define N_CHECKINS 3
#define START_POS Coord(0, 0)
#define END_POS Coord(1, 0)

struct TourCounter {
  bool input();
  int countTours();

  inline int tryTo(const struct Coord& to);
  inline bool move(const struct Coord& to);

  inline int nextCheckIn() const;
  inline bool checkIn() const;

  Map _map;
  std::pair<struct Coord, int> _checkIns[N_CHECKINS + 1]; //U: Check-ins in order
  struct Coord _pos; //U: Current position of the robot
  int _step;
#ifdef DEBUG
  ulong _nodes;
#endif
};
