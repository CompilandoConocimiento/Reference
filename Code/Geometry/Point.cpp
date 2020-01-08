template <typename number>
struct point {
  number x, y;

  point(number x = 0, number y = 0) : x(x), y(y) {}

  point operator+(const point& p) const { return {x + p.x, y + p.y}; }
  point operator-(const point& p) const { return {x - p.x, y - p.y}; }
  point operator*(number k) const { return {x * k, y * k}; }
  point operator/(number k) const { return {x / k, y / k}; }

  point operator+=(const point& p)  { *this = *this + p; return *this; }
  point operator-=(const point& p)  { *this = *this - p; return *this; }
  point operator*=(const number& p) { *this = *this * p; return *this; }
  point operator/=(const number& p) { *this = *this / p; return *this; }

  bool operator==(const point& p) const { return x == p.x and y == p.y; }
  bool operator!=(const point& p) const { return not(*this == p); }

  bool operator<(const point& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator>(const point& p) const { return x != p.x ? x > p.x : y > p.y; }

  bool operator<=(const point& p) const { return (*this == p) or *this < p; }
  bool operator>=(const point& p) const { return (*this == p) or *this > p; }

  friend std::istream& operator>>(std::istream& is, const point& p) {
    return is >> p.x >> p.y;
  }

  friend std::ostream& operator<<(std::ostream& os, const point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
  }

  // Operations
  auto norm() -> number const { return { x * x + y * y }; }

  auto length() -> number const { return sqrtl(norm()); }

  auto perpendicular() -> point const { return {-y, x}; }

  auto unit() -> point const { return (*this) / length(); }

  auto rotate(number angle) -> point const {
    return {x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle)};
  }

};

template <typename T>
auto dot(const point<T>& p, const point<T>& q) -> point<T> {
  return { p.x* q.x + p.y* q.y };
}

template <typename T>
auto cross(const point<T>& p, const point<T>& q) -> point<T> {
  return { p.x* q.y - p.y* q.x };
}
