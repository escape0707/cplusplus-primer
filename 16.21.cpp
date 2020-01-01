#include <iostream>
#include <memory>
#include <string>

class DebugDelete {
 public:
  DebugDelete(std::ostream &s = std::cerr) : os(s) {}
  template <typename T>
  void operator()(T *p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

 private:
  std::ostream &os;
};

int main() {
  std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
  std::unique_ptr<std::string, DebugDelete> sp(new std::string, DebugDelete());
}
