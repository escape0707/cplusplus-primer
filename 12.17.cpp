#include <memory>

using std::unique_ptr;

int main() {
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  using intp = unique_ptr<int>;
  // intp p0(ix);  // invalid conversion from int
  // intp p1(pi);  // illegal, using smart pointer for memory not allocated by new
  intp p2(pi2); // legal, just don't use pi2 after p2 deconstructed
  // intp p3(&ix);  // illegal, using smart pointer for memory not allocated by new
  intp p4(new int(2048));
  // intp p5(p2.get())  // illegal, two unique_ptr to same object;
}
