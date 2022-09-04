#include "tourCounter.h"
#include <iostream>

int main() {
  TourCounter tc; ulong c = 0;
  while (tc.input()) {
    std::cout << "Case " << ++c << ": " << tc.countTours() << std::endl;
#ifdef DEBUG
    std::cout << tc._nodes << std::endl;
#endif
  }
  return 0;
}
