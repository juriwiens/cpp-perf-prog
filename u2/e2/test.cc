#include <iostream>
#include <cassert>
#include "rational.hh"
#include "gcd.hh"

int main() {
  const Rational r_null{};
  assert(r_null.numerator() == 0);
  assert(r_null.denominator() == 1);

  const Rational r_two{2};
  assert(r_two.numerator() == 2);
  assert(r_two.denominator() == 1);

  const Rational r_one_third{2, 6};
  assert(r_one_third.numerator() == 1);
  assert(r_one_third.denominator() == 3);

  const Rational r_minus_one_third{-2, 6};
  assert(r_minus_one_third.numerator() == -1);
  assert(r_minus_one_third.denominator() == 3);

  // Test recip
  assert(recip(r_one_third) == (Rational{3}));
  assert(recip(r_minus_one_third) == (Rational{-3}));
  assert(recip(r_null) == r_null);

  // Test == operator
  const Rational r_one_third2{3, 9};
  assert(r_one_third == r_one_third2);

  // Test < operator
  const Rational r_two_fifth{2, 5};
  assert(r_one_third < r_two_fifth);

  // Test > operator
  assert(r_two_fifth > r_one_third);

  // Test <= operator
  assert(r_one_third <= r_two_fifth);
  assert(r_one_third <= r_one_third2);

  // Test >= operator
  assert(r_two_fifth >= r_one_third);
  assert(r_one_third >= r_one_third2);

  // Test negation operator
  assert(-r_one_third == r_minus_one_third);
  // assert(-(-r_one_third)) == r_one_third);

  // Test addition operator
  assert(Rational{r_one_third + r_two_fifth + r_two} == (Rational{41, 15}));

  // Test substraction operator
  assert(Rational{r_one_third - r_two_fifth - r_two} == (Rational{-31, 15}));

  // Test multiplication operator
  assert(Rational{r_two * r_two_fifth * r_minus_one_third} == (Rational{-4, 15}));

  // Test division operator
  assert(Rational{r_two / r_two_fifth / r_minus_one_third} == (Rational{-15}));

  // Test += operator
  Rational r1{1, 3};
  r1 += r_two_fifth;
  assert(r1 == (Rational{11, 15}));

  // Test -= operator
  Rational r2{1, 3};
  r2 -= r_two_fifth;
  assert(r2 == (Rational{-1, 15}));

  // Test *= operator
  Rational r3{1, 3};
  r3 *= r_two_fifth;
  assert(r3 == (Rational{2, 15}));

  // Test /= operator
  Rational r4{1, 3};
  r4 /= r_two_fifth;
  assert(r4 == (Rational{5, 6}));

  // Test << and >> operator
  // Rational r_in;
  // std::cin >> r_in;
  // std::cout << r_in << std::endl;
}
