// (b)(c)(d) is illegal

#include <memory>

using std::make_shared;
using std::shared_ptr;

void process(shared_ptr<int> ptr) {}

int main() {
  auto p = new int();
  auto sp = make_shared<int>();
  process(sp);
  // process(new int());  // can't implicitly convert pointer to shared_ptr
  // process(p);          // can't implicitly convert pointer to shared_ptr

  // compiles but delete ptr will cause dual-delete
  process(shared_ptr<int>(p));
}