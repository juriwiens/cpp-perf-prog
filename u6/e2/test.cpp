#include "Triangle.hpp"

#include <cassert>

int main() {
  using triangle::Triangle;
  using Point = triangle::Triangle::Point;

  auto t1p0 = Point{1.0, 1.0};
  auto t1p1 = Point{1.0, 3.0};
  auto t1p2 = Point{2.0, 1.0};
  auto t1 = Triangle{&t1p0, &t1p1, &t1p2};

  auto t2p0 = t1p1;
  auto t2p1 = Point{1.0, 5.0};
  auto t2p2 = Point{2.0, 5.0};
  auto t2 = Triangle{&t2p0, &t2p1, &t2p2};

  auto t3p0 = t1p1;
  auto t3p1 = t1p2;
  auto t3p2 = Point{2.0, 2.0};
  auto t3 = Triangle{&t3p0, &t3p1, &t3p2};

  auto t4 = t1;

  assert(triangle::isConnected(t1, t2));
  assert(triangle::isConnected(t1, t3));
  assert(triangle::isConnected(t1, t4));

  assert(!triangle::isAdjacent(t1, t2));
  assert(triangle::isAdjacent(t1, t3));
  assert(triangle::isAdjacent(t1, t4));

  assert(!triangle::isEqual(t1, t2));
  assert(!triangle::isEqual(t1, t3));
  assert(triangle::isEqual(t1, t4));

  Triangle* patch[]{&t1, &t3, &t4};
  Triangle* non_patch[]{&t1, &t2, &t4};
  assert(triangle::isPatch(patch, 3));
  assert(!triangle::isPatch(non_patch, 3));

  assert(triangle::area(t1) == 1.0);
}
