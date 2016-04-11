#include <iostream>
#include <cassert>

/**
 * C++ implementation of Java's & operator.
 * Uses the fact that all arguments get evaluated anyway.
 */
bool and_(bool a, bool b) {
  return a && b;
}

int main() {
  int i = 0;
  int j = 0;

  i++ && j++;
  std::cout << "i: " << i << " j: " << j << std::endl;
  assert(i == 1);
  assert(j == 0);

  // Reset i and j
  i = 0;
  j = 0;

  and_(i++, j++);
  std::cout << "i: " << i << " j: " << j << std::endl;
  assert(i == 1);
  assert(j == 1);
}
