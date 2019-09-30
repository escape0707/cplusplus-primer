#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  // initialize counters for each sequence
  unsigned fCnt = 0, lCnt = 0, iCnt = 0;
  char ch;
	// i don't want to consider 'fff', etc even that's easily doable
  while (cin >> ch) {
    if (ch == 'f') {
      switch (cin >> ch, ch) {
        case 'f':
          ++fCnt;
          break;
        case 'l':
          ++lCnt;
          break;
        case 'i':
          ++iCnt;
          break;
      }
    }
  }
  // print results
  cout << "Number of ff: \t" << fCnt << '\n'
       << "Number of fl: \t" << lCnt << '\n'
       << "Number of fi: \t" << iCnt << endl;


}
