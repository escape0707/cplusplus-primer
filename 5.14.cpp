#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  string freq;
  int freq_cnt = 0;

  string prev;
  if (cin >> prev) {
    int cnt = 1;
    string curr;
    while (cin >> curr) {
      if (curr == prev) {
        ++cnt;
      } else {  // curr != prev
        if (cnt > freq_cnt) {
          freq = prev;
          freq_cnt = cnt;
        }
        // reset prev & cnt
        prev = curr;
        cnt = 1;
      }
    }
    // process last word-count result
    if (cnt > freq_cnt) {
      // update freq & freq_cnt
      freq = prev;
      freq_cnt = cnt;
    }
    cout << freq << ": " << freq_cnt << endl;
  } else {  // no input!
    cout << "No input." << endl;
  }


}
