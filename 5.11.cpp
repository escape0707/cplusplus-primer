#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  // initialize counters for each vowel
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0,
           nCnt = 0;
  char ch;
  while (cin.get(ch)) {
    // if ch is a vowel, increment the appropriate counter
    switch (ch) {
      case 'a':
      case 'A':
        ++aCnt;
        break;
      case 'e':
      case 'E':
        ++eCnt;
        break;
      case 'i':
      case 'I':
        ++iCnt;
        break;
      case 'o':
      case 'O':
        ++oCnt;
        break;
      case 'u':
      case 'U':
        ++uCnt;
        break;
      case ' ':
        ++sCnt;
        break;
      case '\t':
        ++tCnt;
        break;
      case '\n':
        ++nCnt;
        break;
    }
  }
  // print results
  cout << "Number of vowel a: \t" << aCnt << '\n'
       << "Number of vowel e: \t" << eCnt << '\n'
       << "Number of vowel i: \t" << iCnt << '\n'
       << "Number of vowel o: \t" << oCnt << '\n'
       << "NUmber of vowel u: \t" << uCnt << '\n'
       << "NUmber of blank space: \t" << sCnt << '\n'
       << "NUmber of tab: \t\t" << tCnt << '\n'
       << "NUmber of newline: \t" << nCnt << endl;
}
