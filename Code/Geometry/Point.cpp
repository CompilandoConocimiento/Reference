template <typename number> struct point {
  number x, y;

  point(number x = 0, number y = 0) : x(x), y(y) {}

  point operator+(const point &p) const { return {x + p.x, y + p.y}; }
  point operator-(const point &p) const { return {x - p.x, y - p.y}; }
  point operator*(number k) const { return {x * k, y * k}; }
  point operator/(number k) const { return {x / k, y / k}; }

  point operator+=(const point &p)  { *this = *this + p; return *this; }
  point operator-=(const point &p)  { *this = *this - p; return *this; }
  point operator*=(const number &p) { *this = *this * p; return *this; }
  point operator/=(const number &p) { *this = *this / p; return *this; }

  bool operator==(const point &p) const { return x == p.x and y == p.y; }
  bool operator!=(const point &p) const { return not(*this == p); }

  bool operator<(const point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator>(const point &p) const { return x != p.x ? x > p.x : y > p.y; }

  bool operator<=(const point &p) const { return (*this == p) or *this < p; }
  bool operator>=(const point &p) const { return (*this == p) or *this > p; }

  friend std::istream &operator>>(std::istream &is, const point &p) { return is >> p.x >> p.y; }
  friend std::ostream &operator<<(std::ostream &os, const point &p) { 
    return os << "(" << p.x << ", " << p.y << ")";
  }
};
