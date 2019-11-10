#pragma once

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
  void some_member() const;
  Screen move(pos r, pos c);
  Screen set(char);
  Screen set(pos, pos, char);
  // display overloaded on whether the object is const or not
  Screen display(std::ostream &os) {
    do_display(os);
    return *this;
  }
  const Screen display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

 private:
  // function to do the work of displaying a Screen
  void do_display(std::ostream &os) const { os << contents; }
  mutable size_t access_ctr;  // may change even in a const object
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

// we can specify inline on the definition
inline Screen Screen::move(pos r, pos c) {
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

inline Screen Screen::set(char c) {
  contents[cursor] = c;  // set the new value at the current cursor location
  return *this;          // return this object as an lvalue
}

inline Screen Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;  // set specified location to given value
  return *this;                    // return this object as an lvalue
}
