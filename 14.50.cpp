struct LongDouble {
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

int main() {
  LongDouble ldObj;
  // __attribute__((unused)) int ex1 = ldObj; // error
  __attribute__((unused)) float ex2 = ldObj; // operator float()
}
