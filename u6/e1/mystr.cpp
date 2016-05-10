#include "mystr.hpp"
#include <iostream>

// Returns a negative value if s1 is lexicographically “less” than s2,
// 0 if they are equal, and a positive value if s1 is “greater” than s2
int mystr::strcmp(char const* s1, char const* s2) {
  if (*s1 != '\0' && *s2 == '\0') return *s1;
  if (*s1 == '\0' && *s2 != '\0') return *s2;
  if (*s1 == '\0' && *s2 == '\0') return 0;
  if (*s1 != *s2) return *s1 - *s2;
  return mystr::strcmp(s1 + 1, s2 + 1);
}

char const* strrchr_helper(char const* s, int c, char const* last) {
  if (*s == '\0') return last;
  char const* next_last = *s == c ? s : last;
  return strrchr_helper(s + 1, c, next_last);
}

// Returns a pointer to the last occurrence of character c in string s,
// or a NULL pointer if s does not contain c
char const* mystr::strrchr(char const* s, int c) {
  return strrchr_helper(s, c, NULL);
}

// Checks if `str` starts with `start`
bool mystr::starts_with(char const* str, char const* start) {
  // Reached end of t, so s does start with t
  if (*start == '\0') return true;
  // Reached end of s (before end of t was reached), so s does not start with t
  if (*str == '\0') return false;
  // Values behind s and t are not equal, so s doest not start with t
  if (*str != *start) return false;
  // Else values behind s and t are equal, so check the next chars
  return starts_with(str + 1, start + 1);
}

// Returns a pointer to the first occurrence of string t in string s,
// or a NULL pointer if s does not contain t
char const* mystr::strstr(char const* s, char const* t) {
  if (*s == '\0' || *t == '\0') return NULL; // Reached end
  if (starts_with(s, t)) return s;
  return strstr(s + 1, t); // Move pointer for starts_with check to next char
}
