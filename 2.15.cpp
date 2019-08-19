int main() {
  int ival = 1024;
  int &refVal = ival;  // refVal refers to (is another name for) ival
  int &refVal2;        // error: a reference must be initialized
}