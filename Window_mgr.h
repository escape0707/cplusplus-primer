#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>

class Screen;

class Window_mgr {
 public:
  // default constructor needed because can't use in-class initialization for
  // screens now
  Window_mgr();
  // location ID for each screen on the window
  using ScreenIndex = std::vector<Screen>::size_type;
  // reset the Screen at the given position to all blanks
  void clear(ScreenIndex);

 private:
  // Screens this Window_mgr is tracking
  // by default, a Window_mgr has one standard sized blank Screen
  std::vector<Screen> screens;
};

#include "Screen.h"

#endif
