#include "Window_mgr.h"

Window_mgr::Window_mgr() {
  screens = {Screen(24, 80, ' ')};
}

void Window_mgr::clear(ScreenIndex i) {
  // s is a reference to the Screen we want to clear
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}
