#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
 public:
  using pos = std::string::size_type;
  Screen() = default;  // needed because Screen has other constructors
  // cursor initialized to 0 by its in-class initializer
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  // get the character at the cursor
  char get() const { return contents[cursor]; }
  char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  void some_member() const;

 private:
  mutable size_t access_ctr;  // may change even in a const object
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

// we can specify inline on the definition
inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;  // compute the row location
  cursor = row + c;     // move cursor to the column within that row
  return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const {
  pos row = r * width;       // compute the row location
  return contents[row + c];  // return character at the given column
}

void Screen::some_member() const {
  ++access_ctr;  // keep a count of the calls to any member function
  // whatever other work this member needs to do
}

#endif
