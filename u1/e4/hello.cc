#include <iostream>

int main() {
  std::string whom {"World"};
  int&& i{0}; // This works only since C++11
  std::cout << "Hello " << whom << "!" << std::endl;
}
