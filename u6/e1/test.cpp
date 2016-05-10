#include <cassert>
#include <iostream>

#include "mystr.hpp"

// bool expectIntEquals(int actual, int expected) {}

int main() {
  assert(mystr::strcmp("a", "a") == 0);
  assert(mystr::strcmp("a", "b") == -1);
  assert(mystr::strcmp("b", "a") == 1);
  assert(mystr::strcmp("_a", "_b") == -1);
  assert(mystr::strcmp("a_", "b") == -1);
  assert(mystr::strcmp("a", "b_") == -1);

  assert(mystr::starts_with("Test1", "Test"));
  assert(!mystr::starts_with("_Test1", "Test"));

  char const* s1 = "Test1";
  char const* s1_pad = "__Test1";
  assert(mystr::strstr(s1, "Test") == s1);
  assert(mystr::strstr(s1_pad, "Test") == (s1_pad + 2));
  assert(mystr::strstr(s1, "X") == NULL);

  char const* s2 = "abcad";
  assert(mystr::strrchr(s2, 'a') == (s2 + 3));
  assert(mystr::strrchr(s2, 'x') == NULL);
}
