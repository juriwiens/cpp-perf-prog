#include <iostream>

int main() {
  int i = 0;
  // We make a mistake by forgetting an equal sign, so we assign 0 to i.
  // The assignment will always be evaluated to 0, so "Hello World" will never get printed.
  // The compiler warns us that an assignment maybe is not what we intended to do.
  if (i = 0) {
    std::cout << "Hello World!" << std::endl;
  }
}
