template <class number>
inline auto getNumberFast() -> number {
  auto result = number {};
  auto isNegative = false;
  auto currentDigit = char {getchar_unlocked()};

  while (currentDigit < '0' or currentDigit > '9') {
    currentDigit = getchar_unlocked();
    if (currentDigit == '-') isNegative = true;
  }

  while ('0' <= currentDigit and currentDigit <= '9') {
    result = (result << 3) + (result << 1);
    result += currentDigit - '0';
    currentDigit = getchar_unlocked();
  }

  return isNegative ? -result : result;
}
