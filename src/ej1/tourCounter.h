#pragma once

#include "utils.h"

#define N_CHECKINS 3
#define START_POS Coord(0, 0)
#define END_POS Coord(1, 0)

struct TourCounter {
  bool input();
  int countTours();

  inline int tryTo(const struct Coord& to);
  inline bool move(const struct Coord& to);

  inline bool inRange() const;
  inline bool checkIn() const;

  inline int nextCheckIn() const;
  inline void setPos(const bool val);

  std::vector<std::vector<bool>> _map; //U: Grid of booleans with true in each position if it's already been visited
  std::vector<std::pair<struct Coord, int>> _checkIns; //U: Check-ins in order
  struct Coord _pos; //U: Current position of the robot
  int _step;
#ifdef DEBUG
  ulong _nodes;
#endif
};
