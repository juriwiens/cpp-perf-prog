#include "gcd.hh"
#include <cstdlib>
#include <cassert>

int gcd(const int a, const int b) {
  return (b == 0) ? std::abs(a) : gcd(b, a % b);
}
