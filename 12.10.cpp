// correct

#include <memory>

using std::shared_ptr;

// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr) {
  // use ptr
}  // ptr goed out of scope and is destroyed

int main() {
  shared_ptr<int> p(new int(42));
  process(shared_ptr<int>(p));
}