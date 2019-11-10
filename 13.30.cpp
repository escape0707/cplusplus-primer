// see also HasPtr.h

#include <iostream>
#include <string>
#include <utility>

class HasPtrV {
  friend void swap(HasPtrV &lhs, HasPtrV &rhs) {
    std::cerr << "Entering swap" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, lhs.i);
  }

 public:
  HasPtrV() = default;
  HasPtrV(const std::string &s) : ps(new std::string(s)) {}
  HasPtrV(const HasPtrV &other) : ps(new std::string(*other.ps)), i(other.i) {}
  HasPtrV &operator=(HasPtrV rhs) {
    swap(*this, rhs);
    return *this;
  }
  ~HasPtrV() { delete ps; }
  // HasPtrV &operator=(const HasPtrV &rhs) {
  //   *ps = *rhs.ps;
  //   i = rhs.i;
  //   return *this;
  // }
  // HasPtrV &operator=(const HasPtrV &rhs) {
  //   std::string *newp = new std::string(*rhs.ps);
  //   delete ps;
  //   ps = newp;
  //   i = rhs.i;
  //   return *this;
  // }

 private:
  std::string *ps = new std::string();
  int i = 0;
};

class HasPtrP {
  friend void swap(HasPtrP &lhs, HasPtrP &rhs) {
    std::cerr << "Entering swap" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
  }

 public:
  HasPtrP() = default;
  HasPtrP(const std::string &s) : ps(new std::string(s)) {}
  HasPtrP(const HasPtrP &other) : ps(other.ps), i(other.i), use(other.use) {
    ++*use;
  }
  HasPtrP &operator=(HasPtrP rhs) {
    swap(*this, rhs);
    return *this;
  }
  // HasPtrP &operator=(const HasPtrP &rhs) {
  //   ++*rhs.use;
  //   if (--*use == 0) {
  //     delete use;
  //     delete ps;
  //   }
  //   ps = rhs.ps;
  //   i = rhs.i;
  //   use = rhs.use;
  //   return *this;
  // }

  ~HasPtrP() {
    if (--*use == 0) {
      delete use;
      delete ps;
    }
  }

 private:
  std::string *ps = new std::string();
  int i = 0;
  std::size_t *use = new std::size_t(1);
};

int main() {
  HasPtrP p1, p2;
  swap(p1, p2);
  p2 = p1;
  HasPtrV v1, v2;
  swap(v1, v2);
  v2 = v1;
}
