class SmallInt {
  friend SmallInt operator+(const SmallInt &, const SmallInt &);

 public:
  SmallInt(int = 0);
  operator int() const { return val; }

 private:
  int val;
};

struct LongDouble {
  LongDouble operator+(const SmallInt &);
};

LongDouble operator+(LongDouble &, double);

int main() {
  SmallInt si;
  LongDouble ld;
  // ld = si + ld;  // can't find other members as in 14.9.2 p. 587, so no match
  ld = ld + si;  // LongDouble::operator+(const SmallInt &) is exact match
}
