#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int grade;
  while (cin >> grade) {
    string finalgrade =
        grade > 90 ? "high pass"
                   : grade > 75 ? "pass"
                                : grade < 60 ? "fail" : "low pass";

    cout << finalgrade << endl;

    if (grade > 90) {
      finalgrade = "high pass";
    } else if (grade > 75) {
      finalgrade = "pass";
    } else if (grade < 60) {
      finalgrade = "fail";
    } else {
      finalgrade = "low pass";
    }
    cout << finalgrade << endl;
  }


}
