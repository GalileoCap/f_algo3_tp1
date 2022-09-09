#pragma once

#include "utils.h"

struct SprinklerList {
  struct Sprinkler;
  SprinklerList(const ulong n, const ulong _l, const ulong _w);

  void emplace(const ulong r, const ulong pos, const ulong cost); //U: Adds a new sprinkler to the queue only if its valid

  inline bool canFill(const uint i, const uint j) const;
  inline bool isFull(const uint last) const;

  int solve(const uint i, const uint j);
  int solve();

  ulong l, w;
  std::vector<struct Sprinkler> sprinklers; //U: A vector sorted by leftLim

  struct Sprinkler {
    Sprinkler(const ulong _r, const ulong _pos, const ulong _cost, const ulong w);

    bool operator<(const struct Sprinkler& s1) const; //U: For the queue

    bool valid; //U: True if it can be part of the solution
    ulong r, pos; long cost;
    double leftLim, rightLim; //U: Positions of intersection with the rectangle
  };
};
