#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

unsigned some_value() {
  return 1;
}

int get_value() {
  return 0;
}

int get_num() {
  static vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  static vector<int>::const_iterator iter = numbers.cbegin();
  if (iter != numbers.end()) {
    return *iter++;
  }
  return *(iter = numbers.cbegin());
}

unsigned get_bufCnt() {
  return 10;
}

int main() {
  unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
  char ch = cin.get();
  switch (ch) {
    case 'a':
      aCnt++;
      break;
    case 'e':
      eCnt++;
      break;
    default:
      iouCnt++;
  }

  vector<int> ivec(10);
  unsigned index = some_value();
  switch (index) {
    case 1: {
      int ix = get_value();
      ivec[ix] = index;
      break;
    }
    default: {
      int ix = ivec.size() - 1;
      ivec[ix] = index;
    }
  }

  unsigned evenCnt = 0, oddCnt = 0;
  int digit = get_num() % 10;
  switch (digit) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
      oddCnt++;
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
      evenCnt++;
      break;
  }

  constexpr unsigned ival = 512, jval = 1024, kval = 4096;
  unsigned bufsize;
  unsigned swt = get_bufCnt();
  switch (swt) {
    case ival:
      bufsize = ival * sizeof(int);
      break;
    case jval:
      bufsize = jval * sizeof(int);
      break;
    case kval:
      bufsize = kval * sizeof(int);
      break;
  }

  return 0;
}
