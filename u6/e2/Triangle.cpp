#include "Triangle.hpp"

#include <cmath>

namespace triangle {

inline bool hasPoint(Triangle t, Triangle::Point p) {
  return t.point0() == p || t.point1() == p || t.point2() == p;
}

bool isConnected(Triangle const& t1, Triangle const& t2) {
  return hasPoint(t1, t2.point0()) || hasPoint(t1, t2.point1()) ||
         hasPoint(t1, t2.point2());
}

bool isAdjacent(Triangle const& t1, Triangle const& t2) {
  return (hasPoint(t1, t2.point0()) && hasPoint(t1, t2.point1())) ||
         (hasPoint(t1, t2.point0()) && hasPoint(t1, t2.point2())) ||
         (hasPoint(t1, t2.point1()) && hasPoint(t1, t2.point2()));
}

bool isEqual(Triangle const& t1, Triangle const& t2) {
  return hasPoint(t1, t2.point0()) && hasPoint(t1, t2.point1()) &&
         hasPoint(t1, t2.point2());
}

bool isPatch(Triangle* const t_ptrs[], std::size_t length) {
  for (auto i = 0; i < length; i++) {
    for (auto j = i + 1; j < length; j++) {
      if (!isAdjacent(*t_ptrs[i], *t_ptrs[j])) return false;
    }
  }
  return true;
}

Triangle::Area area(Triangle const& t) {
  auto const side12 = t.point1() - t.point0();
  auto const side13 = t.point2() - t.point0();
  return std::abs((side12.x() * side13.y() - side12.y() * side13.x()) / 2.0);
}

} // namespace triangle
