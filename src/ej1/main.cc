#include <iostream>
#include "tourCounter.h"

int main() {
  TourCounter tc; int c = 1;
  while (tc.input())
    std::cout << "Case " << c++ << ": " << tc.countTours() << std::endl;
  return 0;
}
