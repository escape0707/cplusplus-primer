#include <memory>

using std::unique_ptr;

int main() {
  unique_ptr<int> a, b;
  // a = b;                 // use of a deleted function
  // unique_ptr<int> c(a);  // use of a deleted function
}
