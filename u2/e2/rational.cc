#include "rational.hh"
#include "gcd.hh"
#include <iostream>
#include <cassert>

// Constructors

Rational::Rational(): numerator_{0}, denominator_{1} {}

Rational::Rational(const Integer numerator)
  : numerator_{numerator}
  , denominator_{1}
  {}

Rational::Rational(const Integer numerator, const Natural denominator) {
  assert(denominator > 0);
  const Natural gcd_val = gcd(numerator < 0 ? -numerator : numerator,
                              denominator);
  assert(gcd_val > 0);
  numerator_ = numerator / gcd_val;
  denominator_ = denominator / gcd_val;
}

// Getters

Rational::Integer Rational::numerator() const { return this->numerator_; }

Rational::Natural Rational::denominator() const { return this->denominator_; }

// Member functions

Rational& Rational::operator+=(Rational const& r) {
  Rational r_tmp { *this + r };
  this->numerator_ = r_tmp.numerator();
  this->denominator_ = r_tmp.denominator();
  return *this;
}

Rational& Rational::operator-=(Rational const& r) {
  Rational r_tmp { *this - r };
  this->numerator_ = r_tmp.numerator();
  this->denominator_ = r_tmp.denominator();
  return *this;
}

Rational& Rational::operator*=(Rational const& r) {
  Rational r_tmp { *this * r };
  this->numerator_ = r_tmp.numerator();
  this->denominator_ = r_tmp.denominator();
  return *this;
}

Rational& Rational::operator/=(Rational const& r) {
  Rational r_tmp { *this / r };
  this->numerator_ = r_tmp.numerator();
  this->denominator_ = r_tmp.denominator();
  return *this;
}

// Non-member functions

Rational recip(Rational const& r) {
  if (r.numerator() > 0) {
    return Rational{ r.denominator(), r.numerator() };
  } else if (r.numerator() == 0) {
    return Rational{};
  } else { // r.numerator < 0
    return Rational{ -(r.denominator()), -(r.numerator()) };
  }
}

// Operators

bool operator==(Rational const& r1, Rational const& r2) {
  return r1.numerator() == r2.numerator()
      && r1.denominator() == r2.denominator();
}

bool operator<(Rational const& r1, Rational const& r2) {
  return r1.numerator() * r2.denominator() < r2.numerator() * r1.denominator();
}

bool operator>(Rational const& r1, Rational const& r2) {
  return r1.numerator() * r2.denominator() > r2.numerator() * r1.denominator();
}

bool operator>=(Rational const& r1, Rational const& r2) {
  return !(r1 < r2);
}

bool operator<=(Rational const& r1, Rational const& r2) {
  return !(r1 > r2);
}

Rational operator-(Rational const& r) {
  return Rational{ -r.numerator(), r.denominator() };
}

Rational operator+(Rational const& r1, Rational const& r2) {
  const Rational::Integer num = r1.numerator() * r2.denominator() +
                                r2.numerator() * r1.denominator();
  const Rational::Natural denom = r1.denominator() * r2.denominator();
  return Rational{ num, denom };
}

Rational operator-(Rational const& r1, Rational const& r2) {
  return r1 + (-r2);
}

Rational operator*(Rational const& r1, Rational const& r2) {
  return Rational{
    r1.numerator() * r2.numerator(),
    r1.denominator() * r2.denominator()
  };
}

Rational operator/(Rational const& r1, Rational const& r2) {
  return r1 * recip(r2);
}

std::ostream& operator<<(std::ostream& os, Rational const& r) {
  return os << r.numerator() << "/" << r.denominator();
}

std::istream& operator>>(std::istream& is, Rational& r) {
  Rational::Integer num;
  Rational::Natural denom;
  std::cin >> num;
  std::cin >> denom;
  r = Rational { num, denom };
  return is;
}
