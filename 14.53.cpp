class SmallInt {
  friend SmallInt operator+(const SmallInt &, const SmallInt &);

 public:
  SmallInt(int = 0) {}
  operator int() const { return val; }

 private:
  int val;
};

int main() {
  SmallInt s1;
  // double d = s1 + 3.14;  // ambiguous
  __attribute__((unused)) double d = s1.operator int() + 3.14;
}
