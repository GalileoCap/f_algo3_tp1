#include "tourCounter.h"

bool TourCounter::inputTests(int rows, int cols, const struct Coord& checkin1, const struct Coord& checkin2, const struct Coord& checkin3){
    //Reads the map's dimensions and check-ins from parameters

    if (rows == 0 || cols == 0) return false; //Invalid size, assume end of test
    _map = Map(rows, cols);

    //Read the check-ins
    _checkIns[1] = std::make_pair(checkin1, rows * cols / 4);
    _checkIns[2] = std::make_pair(checkin2, rows * cols / 2);
    _checkIns[3] = std::make_pair(checkin3, 3 * rows * cols / 4);

    //Include the beginning and ending positions
    _checkIns[0] = std::make_pair(START_POS, 1);
    _checkIns[N_CHECKINS + 1] = std::make_pair(END_POS, rows * cols);

    _pos = START_POS;
    _map.setAt(_pos, true);
    _step = 1;

    return true;
}

bool TourCounter::input() { //U: Reads the map's dimensions and check-ins from stdin and resets
  int rows, cols;
  std::cin >> rows >> cols;
  if (rows == 0 || cols == 0) return false; //A: Invalid size, assume end of test

  _map = Map(rows, cols);
  for (uint i = 1, row, col; i <= N_CHECKINS; i++) { //A: Read the check-ins
    std::cin >> row >> col;
    _checkIns[i] = std::make_pair(Coord(col, row), (i) * rows * cols / 4);
  }
  _checkIns[0] = std::make_pair(START_POS, 1); //A: Include the beginning and ending positions
  _checkIns[N_CHECKINS + 1] = std::make_pair(END_POS, rows * cols);

  _pos = START_POS;
  _map.setAt(_pos, true);
  _step = 1;
#ifdef DEBUG
  _nodes = 0;
#endif

  return true;
}

inline bool TourCounter::checkChecks() const { //U: Is in time for the check-ins
  bool res = true;
  for (const auto& checkIn : _checkIns) //TODO: Unroll
    if (checkIn.second <= _step) res &= _map.getAt(checkIn.first); //A: Should've checked-in
    else res &= (!_map.getAt(checkIn.first) && _pos.manhattan(checkIn.first) <= (checkIn.second - _step)); //A: Hasn't been there and is in range for this check-in
  return res;
}

inline ulong TourCounter::tryTo(const struct Coord& to) { //A: Tries moving to one side
  ulong res = 0; 

  if (_map.check(_pos + to)) { //A: It's a valid move map-wise
    _step++; _pos += to; _map.setAt(_pos, true); //A: Move in this direction
    if (checkChecks()) //A: The check-ins are in check
      res += countTours(); //A: Count downstream
    _map.setAt(_pos, false); _pos -= to; _step--; //A: Move back
  }

  return res;
}

ulong TourCounter::countTours() {
#ifdef DEBUG
  _nodes++;
#endif
  if (_step == (_map.rows * _map.cols)) //A: Reached the last step
    return _pos == END_POS;
  else //A: Recursive step, try moving to all sides
    return tryTo(LEFT) + tryTo(RIGHT) + tryTo(UP) + tryTo(DOWN);
}
