#include "utils.h"
#include "sprinkler.h"

bool dequals(const double a, const double b) {
  return std::abs(a - b) <= std::numeric_limits<double>::epsilon();
}

int main(void) {
  while (true) {
    ulong n, l, w;
    uint _scan = scanf("%lu %lu %lu", &n, &l, &w);
    if (feof(stdin)) break;

    struct SprinklerList sprinklers(l, w);
    for (ulong i = 0, r, pos; i < n; i++) {
      _scan = scanf("%lu %lu", &pos, &r);
      sprinklers.emplace(r, pos);
    }

    printf("%i\n", sprinklers.solve());
  }

  return 0;
}
