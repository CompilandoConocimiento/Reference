#include <cmath>
#include <iostream>

template <typename number = long double>
struct decimal {
  static constexpr number epsilon = 1e-9;
  number x;
  decimal(number x = 0) : x(x) {}

  decimal operator+(const decimal &p) const { return {x + p.x}; }
  decimal operator-(const decimal &p) const { return {x - p.x}; }
  decimal operator*(const decimal &p) const { return {x * p.x}; }
  decimal operator/(const decimal &p) const { return {x / p.x}; }

  decimal operator+=(const decimal &p) { *this = *this + p; return *this; }
  decimal operator-=(const decimal &p) { *this = *this - p; return *this; }
  decimal operator*=(const decimal &p) { *this = *this * p; return *this; }
  decimal operator/=(const decimal &p) { *this = *this / p; return *this; }

  bool operator==(const decimal &p) const { return abs(x - p.x) <= epsilon; }
  bool operator!=(const decimal &p) const { return not(*this == p); }

  bool operator<(const decimal &p) const { return p.x - x > epsilon; }
  bool operator>(const decimal &p) const { return x - p.x > epsilon; }

  bool operator>=(const decimal &p) const { return x - p.x >= -epsilon; }
  bool operator<=(const decimal &p) const { return p.x - x >= -epsilon; }

  int sign() {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
  }

  friend std::istream &operator>>(std::istream &is, const decimal &p) { return is >> p.x; }
  friend std::ostream &operator<<(std::ostream &os, const decimal &p) { return os << p.x; }
};