#include "sprinkler.h"

pricedSprinklerList::pricedSprinklerList(const ulong n, const ulong _l, const ulong _w) : l(_l), w(_w) {
  sprinklers.reserve(n);
}

void pricedSprinklerList::emplace(const ulong r, const ulong pos, const ulong cost) { //U: Adds a new sprinkler to the queue only if its valid
  struct Sprinkler s(r, pos, cost, w);
  if (s.valid) sprinklers.push_back(s);
}

pricedSprinklerList::Sprinkler::Sprinkler(const ulong _r, const ulong _pos, const ulong _cost, const ulong w) : valid((2 * _r) >= w), r(_r), pos(_pos),cost(_cost) {
  if (valid) {
    double dpos = std::sqrt((double)(r * r) - (double)(w * w) / 4); //A: Solve for x^2 + w^2 = r^2
    leftLim = (double)pos - dpos;
    rightLim = (double)pos + dpos;
  }
}

bool pricedSprinklerList::Sprinkler::operator<(const struct Sprinkler& s1) const { //U: For the queue
  return leftLim < s1.leftLim;
}

inline bool pricedSprinklerList::canFill(const uint i, const uint j) const {
  return !(sprinklers[i].leftLim > ((j != -1) ? sprinklers[j].rightLim : 0));
}

inline bool pricedSprinklerList::isFull(const uint last) const {
  return l == 0 || ((last != -1) && !(sprinklers[last].rightLim < (double)l));
}

int pricedSprinklerList::solve() {
  std::vector<int> M(sprinklers.size()+1);
  std::sort(sprinklers.begin(), sprinklers.end());

  for (int i = sprinklers.size(); i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (i == sprinklers.size()) M[j] = -(!isFull(j-1));
      else if (isFull(j-1)) M[j] = 0;
      else if (!canFill(i, j-1)) M[j] = -1;
      else {
        int l = M[j], r = M[i+1];
        if (r != -1) r += sprinklers[i].cost;

        if (l == -1) M[j] = r;
        else if (r == -1) M[j] = l;
        else M[j] = std::min(l, r);
      }

  return M[0];
}
