#include <iostream>
int main() {
  int sum = 0, val = 0;
  // keep executing the while as long as val is less than or equal to 10
  while (++val, val <= 10)
    sum += val;

  // or:
  // while (sum += ++val, val <= 10)
  //   ;

  // this is not a good example of the usage of comma operator
  // better to use for loop to solve that problem
  // for (int val = 1; val <= 10; ++val) {
  //   sum += val;
  // }

  // the proper usage examples are like:
  //
  // while (update(y), test(y)) {
  // }
  //
  // for (int i; i = get_i(), i != sentinel;) {
  // }
  //
  // or:
  //
  // for (int i = 0, j = 1; i < j; ++i, --j) {
  // }

  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
  return 0;
}