#include "sprinkler.h"

SprinklerList::SprinklerList(const ulong _l, const ulong _w) : l(_l), w(_w) {}

void SprinklerList::emplace(const ulong r, const ulong pos) { //U: Adds a new sprinkler to the queue only if its valid
  struct Sprinkler s(r, pos, w);
  if (s.valid) queue.push(s);
}

SprinklerList::Sprinkler::Sprinkler(const ulong _r, const ulong _pos, const ulong w) : valid((2 * _r) >= w), r(_r), pos(_pos) {
  if (valid) {
    double dpos = std::sqrt((double)(r * r) - (double)(w * w) / 4); //A: Solve for x^2 + (w/2)^2 = r^2
    leftLim = (double)pos - dpos;
    rightLim = (double)pos + dpos;
  }
}

bool SprinklerList::Sprinkler::operator<(const struct Sprinkler& s1) const { //U: For the queue
  return leftLim > s1.leftLim;
}

int SprinklerList::solve() {
  int res = 0; double areaCovered = 0;
  while (!queue.empty() && areaCovered < (double)l) { //A: We haven't covered the entire area, and there's more sprinklers
    struct Sprinkler s0 = queue.top(); queue.pop();

    if (s0.leftLim > areaCovered) break; //A: Doesn't help
    else while (!queue.empty()) { //A: Look for the furthest reaching sprinkler
      struct Sprinkler s1 = queue.top();
      if (s1.leftLim > areaCovered) break; //A: Doesn't help
      else {
        queue.pop();
        if ((s1.rightLim - areaCovered) > (s0.rightLim - areaCovered)) s0 = s1; //A: Adds more new areaCovered
      }
    }

    res++;
    areaCovered = s0.rightLim;
  }
  return (areaCovered < (double)l) ? -1 : res;
}
