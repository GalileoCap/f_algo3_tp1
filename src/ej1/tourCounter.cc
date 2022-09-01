#include "tourCounter.h"
#include <utility>

bool TourCounter::input() {
  int rows, cols;
  std::cin >> rows >> cols;
  if (rows == 0 || cols == 0) return false;
  _map = std::vector<std::vector<bool>> (rows, std::vector<bool> (cols, false));

  _checkIns.resize(N_CHECKINS + 1);
  for (int i = 0, row, col; i < N_CHECKINS; i++) {
    std::cin >> row >> col;
    _checkIns[i] = std::make_pair(Coord(col, row), (i+1) * rows * cols / 4);
  }
  _checkIns[N_CHECKINS] = std::make_pair(END_POS, rows * cols);

  _pos = START_POS;
  _step = 1;
  _map[_pos._y][_pos._x] = true;
  return true;
}

inline void TourCounter::setPos(const bool val) {
  _map[_pos._y][_pos._x] = val;
}

inline bool TourCounter::inRange() const {
  return _pos._y >= 0 && _pos._y < _map.size() && _pos._x >= 0 && _pos._x < _map[0].size();
}

inline int TourCounter::nextCheckIn() const {
  for (int i = 0; i < N_CHECKINS; i++)
    if (_step <= _checkIns[i].second) return i;
  return N_CHECKINS;
}

inline bool TourCounter::checkIn() const {
  int next = nextCheckIn();
  return _pos.manhattan(_checkIns[next].first) <= (_checkIns[next].second - _step);
}

inline bool TourCounter::move(const struct Coord& to) {
  _pos += to;
  return (
    inRange() &&
    !_map[_pos._y][_pos._x] &&
    checkIn()
  );
}

inline int TourCounter::tryTo(const struct Coord& to) {
  _step++;
  int res = 0;
  if (move(to)) { //A: Try moving to the left
    setPos(true);
    res += countTours(); //A: Count downstream
    setPos(false);
  }
  move(-to); _step--; //A: Undo this step
  return res;
}

int TourCounter::countTours() {
  if (_step == (_map.size() * _map[0].size())) return _pos == END_POS; //A: Reached the last step
  else {
    return tryTo(LEFT) + tryTo(RIGHT) + tryTo(UP) + tryTo(DOWN); //A: Recursive step, try moving to all sides
  }
}
