#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Vector2D.hpp"

namespace triangle {

class Triangle {
public:
  using Point = linalg::Vector2D;
  using Area = linalg::Vector2D::Coord;

private:
  Point* p0_;
  Point* p1_;
  Point* p2_;

public:
  Triangle(Point* point0, Point* point1, Point* point2)
      : p0_{point0}, p1_{point1}, p2_{point2} {}

  Point& point0() const { return *p0_; }
  Point& point1() const { return *p1_; }
  Point& point2() const { return *p2_; }
};

bool hasPoint(Triangle, Triangle::Point);

bool isConnected(Triangle const&, Triangle const&);
bool isAdjacent(Triangle const&, Triangle const&);
bool isEqual(Triangle const&, Triangle const&);

bool isPatch(Triangle* const triangle_ptrs[], std::size_t length);

Triangle::Area area(Triangle const&);

} // namespace triangle

#endif
