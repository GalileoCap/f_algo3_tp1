#include "tourCounter.h"

bool TourCounter::input() {
  int rows, cols;
  std::cin >> rows >> cols;
  if (rows == 0 || cols == 0) return false; //A: Invalid size, assume end of test

  _map = Map(rows, cols);
  for (uint i = 1, row, col; i <= N_CHECKINS; i++) {
    std::cin >> row >> col;
    _checkIns[i] = std::make_pair(Coord(col, row), (i) * rows * cols / 4);
  }
  _checkIns[0] = std::make_pair(START_POS, 0);
  _checkIns[N_CHECKINS + 1] = std::make_pair(END_POS, rows * cols);

  _pos = START_POS + UP; //A: Skip first step
  _map.setAt(START_POS, true);
  _map.setAt(_pos, true);
  _step = 2;
#ifdef DEBUG
  _nodes = 0;
#endif

  return true;
}

inline bool TourCounter::checkIn() const {
  bool res = true;
  for (const auto& nextCheckIn : _checkIns)
    res &= nextCheckIn.second < _step || _pos.manhattan(nextCheckIn.first) <= (nextCheckIn.second - _step);
  return res;
}

inline bool TourCounter::move(const struct Coord& to) {
  _pos += to;
  return (
    _map.check(_pos) &&
    checkIn()
  );
}

inline int TourCounter::tryTo(const struct Coord& to) {
  _step++;
  int res = 0;
  if (move(to)) { //A: Try moving to the left
    _map.setAt(_pos, true);
    res += countTours(); //A: Count downstream
    _map.setAt(_pos, false);
  }
  move(-to); _step--; //A: Undo this step
  return res;
}

int TourCounter::countTours() {
#ifdef DEBUG
  _nodes++;
#endif
  if (_step == (_map.rows * _map.cols)) return _pos == END_POS; //A: Reached the last step
  else {
    return tryTo(LEFT) + tryTo(RIGHT) + tryTo(UP) + tryTo(DOWN); //A: Recursive step, try moving to all sides
  }
}
