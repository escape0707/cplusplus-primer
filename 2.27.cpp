#include <iostream>

int main() {
  const double pi = 3.14;     // pi is const; its value may not be changed
  // double *ptr = &pi;       // error: ptr is a plain pointer
  const double *cptr = &pi;   // ok: cptr may point to a double that is const
  // *cptr = 42;              // error: cannot assign to *cptr

  double dval = 3.14;  // dval is a double; its value can be changed
  cptr = &dval;        // ok: but can't change dval through cptr

  int i = 0;
  const int &j = i;
  std::cout << j << ' ' << (i = 1) << ' ' << j << std::endl;

  int errNumb = 0;
  int *const curErr = &errNumb;   // currErr will always point to errNumb
  const double *const pip = &pi;        // pip is a const pointer to a const object
}