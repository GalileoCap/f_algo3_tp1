#pragma once

#include "utils.h"

struct SprinklerList {
  struct Sprinkler;
  SprinklerList(const ulong _l, const ulong _w);

  void emplace(const ulong r, const ulong pos, const ulong cost); //U: Adds a new sprinkler to the queue only if its valid

  int solve();

  ulong l, w;
  std::priority_queue<struct Sprinkler> queue; //U: A queue sorted by leftLim

  struct Sprinkler {
    Sprinkler(const ulong _r, const ulong _pos, const ulong _cost, const ulong w);

    bool operator<(const struct Sprinkler& s1) const; //U: For the queue

    bool valid; //U: True if it can be part of the solution
    ulong r, pos, cost;
    double leftLim, rightLim; //U: Positions of intersection with the rectangle
  };
};
