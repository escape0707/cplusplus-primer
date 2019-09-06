#include "Chapter6.h"

int fact(unsigned val) {
  unsigned ret = 1;
  while (val) {
    ret *= val--;
  }
  return ret;
}
