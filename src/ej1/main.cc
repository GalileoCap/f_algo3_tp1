#include "tourCounter.h"
#include <iostream>

int main() {
  TourCounter tc; int c = 1;
  while (tc.input()) {
    std::cout << "Case " << c++ << ": " << tc.countTours() << std::endl;
#ifdef DEBUG
    std::cout << tc._nodes << std::endl;
#endif
  }
  return 0;
}
