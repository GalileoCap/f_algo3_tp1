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

  inline void setPos(const bool val);

  inline bool inRange() const;
  inline bool atIthCheckIn(const int i) const;
  inline bool checkChecks() const;

  std::vector<std::vector<bool>> _map; //U: Grid of booleans with true in each position if it's already been visited
  std::vector<struct Coord> _checkIns; //U: Check-ins in order
  struct Coord _pos; //U: Current position of the robot
  int _step;
};
