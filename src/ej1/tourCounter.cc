#include "tourCounter.h"

bool TourCounter::input() { //U: Reads the map's dimensions and check-ins from stdin and resets
  int rows, cols;
  std::cin >> rows >> cols;
  if (rows == 0 || cols == 0) return false; //A: Invalid size, assume end of test

  _map = Map(rows, cols);
  for (uint i = 1, row, col; i <= N_CHECKINS; i++) { //A: Read the check-ins
    std::cin >> row >> col;
    _checkIns[i] = std::make_pair(Coord(col, row), (i) * rows * cols / 4);
  }
  _checkIns[0] = std::make_pair(START_POS, 0); //A: Include the beginning and ending positions
  _checkIns[N_CHECKINS + 1] = std::make_pair(END_POS, rows * cols);

  _pos = START_POS + UP; //A: Skip first step
  _map.setAt(START_POS, true);
  _map.setAt(_pos, true);
  _step = 2;
  _memory = Memory<ulong>(rows * cols, rows * cols, -1);
#ifdef DEBUG
  _nodes = 0;
#endif

  return true;
}

inline bool TourCounter::checkChecks() const { //U: Is in time for the check-ins
  bool res = true;
  for (const auto& nextCheckIn : _checkIns) //TODO: Unroll
    res &= (
      nextCheckIn.second < _step || //A: Has already checked-in
      _pos.manhattan(nextCheckIn.first) <= (nextCheckIn.second - _step) //A: Is in time for this check-in
    );
  return res;
}

inline bool TourCounter::check() const { //U: It's in a valid state
  return _map.check(_pos) && checkChecks();
}

inline ulong TourCounter::tryTo(const struct Coord& to) { //A: Tries moving to one side
  _pos += to; _step++; //A: Move in this direction
  ulong res = 0; 
  if (check()) { //A: It was a valid move
    _map.setAt(_pos, true);
    res += countTours(); //A: Count downstream
    _map.setAt(_pos, false); //A: Undo this move
  }
  _pos -= to; _step--; //A: Move back
  return res;
}

ulong TourCounter::countTours() {
#ifdef DEBUG
  _nodes++;
#endif
  if (_step == (_map.rows * _map.cols)) //A: Reached the last step
    return _pos == END_POS;
  else { //A: Recursive step, try moving to all sides
    ulong *res = _memory.getAt(_step - 1, _pos.toUint(_map.cols), _map.hash);
    if (res == nullptr) {
      res = new ulong(tryTo(LEFT) + tryTo(RIGHT) + tryTo(UP) + tryTo(DOWN));
      _memory.setAt(_step - 1, _pos.toUint(_map.cols), _map.hash, res); //TODO: Skip find in setAt
    }
    return *res;
  }
}
