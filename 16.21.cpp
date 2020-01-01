#include <iostream>
#include <memory>
#include <string>

class DebugDelete {
 public:
  DebugDelete(std::ostream &os = std::cerr);
  template <typename T>
  void operator()(T *p) const;

 private:
  std::ostream &os;
};

DebugDelete::DebugDelete(std::ostream &os) : os(os) {}

template <typename T>
void DebugDelete::operator()(T *p) const {
  os << "deleting unique_ptr" << std::endl;
  delete p;
}

int main() {
  double *p = new double;
  DebugDelete d;
  d(p);
  int *ip = new int;
  DebugDelete()(ip);
  std::unique_ptr<int, DebugDelete> uip(new int, DebugDelete());
  std::unique_ptr<std::string, DebugDelete> usp(new std::string, DebugDelete());
}
