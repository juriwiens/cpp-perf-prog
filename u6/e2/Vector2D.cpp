#include "Vector2D.hpp"
#include <iostream>

namespace linalg {

std::ostream& operator<<(std::ostream& os, Vector2D const& v) {
  os << "(" << v.x() << "," << v.y() << ")";
  return os;
}

std::istream& operator>>(std::istream& is, Vector2D& v) {
  char c;
  is >> c; // '(';
  is >> v.x_;
  is >> c; // ',';
  is >> v.y_;
  is >> c; // ')';
  return is;
}

bool operator==(Vector2D const& v1, Vector2D const& v2) {
  return v1.x() == v2.x() && v1.y() == v2.y();
}

Vector2D operator-(Vector2D const& v1, Vector2D const& v2) {
  return Vector2D{v1.x() - v2.x(), v1.y() - v2.y()};
}

} // end of namespace
