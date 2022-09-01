#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using coordinate = std::pair<int, int>;

enum Direction {
  LEFT, RIGHT, UP, DOWN
};

inline Direction anti(const Direction to) {
  switch (to) {
    case LEFT: return RIGHT;
    case RIGHT: return LEFT;
    case UP: return DOWN;
    case DOWN: return UP;
  }
}
