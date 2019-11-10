#pragma once

#include <string>
#include <utility>

#include "Window_mgr.h"

class Screen {
  // Window_mgr members can access the private parts of class Screen
  friend void Window_mgr::clear(ScreenIndex);

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
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);
  // display overloaded on whether the object is const or not
  Screen &display(std::ostream &os) {
    std::as_const(*this).display(os);
    return *this;
  }
  const Screen &display(std::ostream &os) const {
    os << contents;
    return *this;
  }
  pos size() const;

 private:
  mutable size_t access_ctr;  // may change even in a const object
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};
