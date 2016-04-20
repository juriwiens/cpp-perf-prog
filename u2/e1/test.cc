#include <cassert>
#include "gcd.hh"

int main() {
  assert(gcd(1, 1) == 1);
  assert(gcd(37, 600) == 1);
  assert(gcd(20, 100) == 20);
  assert(gcd(-20, 100) == 20);
  assert(gcd(20, -100) == 20);
  assert(gcd(624129, 2061517) == 18913);
}
