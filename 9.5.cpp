template <typename InputIt, typename T>
InputIt find(InputIt begin, const InputIt &end, const T &val) {
  for (; begin != end; ++begin) {
    if (*begin == val) {
      return begin;
    }
  }
  return end;
}
