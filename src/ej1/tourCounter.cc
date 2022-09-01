#include "tourCounter.h"

bool TourCounter::input() {
  int rows, cols;
  std::cin >> rows >> cols;
  if (rows == 0 || cols == 0) return false;
  _map = std::vector<std::vector<bool>> (rows, std::vector<bool> (cols, false));

  _checkIns.resize(N_CHECKINS);
  for (int i = 0, row, col; i < N_CHECKINS; i++) {
    std::cin >> row >> col;
    _checkIns[i] = std::make_pair(row, col);
  }

  _pos = START_POS;
  _step = 1;
  _map[_pos.first][_pos.second] = true;
  return true;
}

inline void TourCounter::setPos(const bool val) {
  _map[_pos.first][_pos.second] = val;
}

inline bool TourCounter::inRange() const {
  return _pos.first >= 0 && _pos.first < _map.size() && _pos.second >= 0 && _pos.second < _map[0].size();
}

inline bool TourCounter::atIthCheckIn(const int i) const {
  return _step == ((i+1) * _map.size() * _map[0].size() / 4);
}

inline bool TourCounter::checkChecks() const {
  for (int i = 0; i < N_CHECKINS; i++)
    if (atIthCheckIn(i)) return _pos == _checkIns[i]; //A: Should be at the i-th check-in
  return true; //A: Default to true
}

inline bool TourCounter::move(const Direction to) {
  switch (to) {
    case LEFT: _pos.second += -1; break;
    case RIGHT: _pos.second += 1; break;
    case UP: _pos.first += 1; break;
    case DOWN: _pos.first += -1; break;
  }
  return inRange() && checkChecks() && !_map[_pos.first][_pos.second];
}

inline int TourCounter::tryTo(const Direction to) {
  _step++;
  int res = 0;
  if (move(to)) { //A: Try moving to the left
    setPos(true);
    res += countTours(); //A: Count downstream
    setPos(false);
  }
  move(anti(to)); _step--; //A: Undo this step
  return res;
}

int TourCounter::countTours() {
  if (_step == (_map.size() * _map[0].size())) return _pos == END_POS; //A: Reached the last step
  else {
    return tryTo(LEFT) + tryTo(RIGHT) + tryTo(UP) + tryTo(DOWN); //A: Recursive step, try moving to all sides
  }
}
