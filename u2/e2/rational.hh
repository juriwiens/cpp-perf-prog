#ifndef RATIONAL_HH_
#define RATIONAL_HH_

#include <iostream>

class Rational {
public:
  using Integer = int;
  using Natural = int;

private:
  Integer numerator_;
  Natural denominator_;

public:
  Rational();
  Rational(const Integer);
  Rational(const Integer, const Natural);

  Integer numerator() const;
  Natural denominator() const;

  Rational& operator+=(Rational const&);
  Rational& operator-=(Rational const&);
  Rational& operator*=(Rational const&);
  Rational& operator/=(Rational const&);

  friend std::ostream& operator<<(std::ostream&, Rational const&);
  friend std::istream& operator>>(std::istream&, Rational&);
};

Rational recip(Rational const&);

bool operator==(Rational const&, Rational const&);
bool operator<(Rational const&, Rational const&);
bool operator>(Rational const&, Rational const&);
bool operator>=(Rational const&, Rational const&);
bool operator<=(Rational const&, Rational const&);

Rational operator-(Rational const&);
Rational operator+(Rational const&, Rational const&);
Rational operator-(Rational const&, Rational const&);
Rational operator*(Rational const&, Rational const&);
Rational operator/(Rational const&, Rational const&);

#endif
