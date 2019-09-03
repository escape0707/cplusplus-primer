#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  string prev;
  if (cin >> prev) {
    string curr;
    while (cin >> curr) {
      if (curr == prev) {
        break;
      } else {
        prev = curr;
      }
    }
    if (cin) { // curr == prev
      cout << prev << endl;
    } else { // curr != prev && !cin
      cout << "No word was repeated." << endl;
    }
  }

  return 0;
}
