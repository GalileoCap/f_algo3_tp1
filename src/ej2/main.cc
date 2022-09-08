#include "utils.h"
#include "sprinkler.h"

int main(void) {
  while (true) {
    ulong n, l, w;
    uint _scan = scanf("%lu %lu %lu", &n, &l, &w);
    if (feof(stdin)) break;

    struct SprinklerList sprinklers(l, w);
    for (uint i = 0; i < n; i++) {
      ulong r, pos;
      _scan = scanf("%lu %lu", &pos, &r);
      sprinklers.emplace(r, pos);
    }

    printf("%i\n", sprinklers.solve());
  }

  return 0;
}
