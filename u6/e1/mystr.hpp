#ifndef MYSTR_H
#define MYSTR_H

namespace mystr {
int strcmp(char const* s1, char const* s2);
char const* strrchr(char const* s, int c);
char const* strstr(char const* s, char const* t);

bool starts_with(char const* str, char const* start);
}

#endif
