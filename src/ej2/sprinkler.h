#pragma once

#include "utils.h"

struct SprinklerList {
  struct Sprinkler;
  SprinklerList(const ulong _l, const ulong _w);

  void emplace(const ulong r, const ulong pos);

  int solve();

  ulong l, w;
  std::priority_queue<struct Sprinkler> queue;

  struct Sprinkler {
    Sprinkler(const ulong _r, const ulong _pos, const ulong w);

    bool operator<(const struct Sprinkler& s1) const;

    bool valid;
    ulong r, pos;
    double leftLim, rightLim;
  };
};
