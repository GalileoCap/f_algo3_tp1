#include "sprinkler.h"

SprinklerList::SprinklerList(const ulong n, const ulong _l, const ulong _w) : l(_l), w(_w) {
  sprinklers.reserve(n);
}

void SprinklerList::emplace(const ulong r, const ulong pos, const ulong cost) { //U: Adds a new sprinkler to the queue only if its valid
  struct Sprinkler s(r, pos, cost, w);
  if (s.valid) sprinklers.push_back(s);
}

SprinklerList::Sprinkler::Sprinkler(const ulong _r, const ulong _pos, const ulong _cost, const ulong w) : valid((2 * _r) >= w), r(_r), pos(_pos),cost(_cost) {
  if (valid) {
    double dpos = std::sqrt((double)(r * r) - (double)(w * w) / 4); //A: Solve for x^2 + w^2 = r^2
    leftLim = (double)pos - dpos;
    rightLim = (double)pos + dpos;
  }
}

bool SprinklerList::Sprinkler::operator<(const struct Sprinkler& s1) const { //U: For the queue
  return leftLim < s1.leftLim;
}

inline bool SprinklerList::canFill(const uint i, const uint j) const {
  return !(sprinklers[i].leftLim > ((j != -1) ? sprinklers[j].rightLim : 0));
}

inline bool SprinklerList::isFull(const uint last) const {
  return l == 0 || ((last != -1) && !(sprinklers[last].rightLim < (double)l));
}

int SprinklerList::solve(const uint i, const uint j) {
  if (i == sprinklers.size()) return -(!isFull(j)); //A: Base case 0 (no more sprinklers): 0 if it's full, -1 if not
  else if (isFull(j)) return 0; //A: Base case 1 (already full)
  else if (!canFill(i, j)) return -1; //A: Base case 2 (can't be filled)
  else {
    int l = solve(i+1, j), r = solve(i+1, i);
    if (r != -1) r += sprinklers[i].cost;

    if (l == -1) return r;
    else if (r == -1) return l;
    else return std::min(l, r);
  }
}

int SprinklerList::solve() {
  std::sort(sprinklers.begin(), sprinklers.end());
  return solve(0, -1);
}
