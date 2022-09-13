#include "utils.h"
#include "sprinkler.h"

int main(void) {
  while (true) {
    ulong n, l, w;
    uint _scan = scanf("%lu %lu %lu", &n, &l, &w);
    if (feof(stdin)) break; //A: No more cases

    struct SprinklerList sprinklers(n, l, w);
    for (uint i = 0; i < n; i++) {
      ulong r, pos, cost;
      _scan = scanf("%lu %lu %lu", &pos, &r, &cost);
      sprinklers.emplace(r, pos, cost);
    }

    printf("%i\n", sprinklers.solve());
  }

  return 0;
}
