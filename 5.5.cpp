#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

  unsigned grade;

  while (cin >> grade) {
    // if grade is less than 60 it's an F, otherwise compute a subscript
    string lettergrade;
    // if failing grade, no need to check for a plus or minus
    if (grade < 60) {
      lettergrade = scores[0];
    } else {
      lettergrade = scores[(grade - 50) / 10];  // fetch the letter grade
      if (grade != 100) {  // add plus or minus only if not already an A++
        if (grade % 10 > 7) {
          lettergrade += '+';  // grades ending in 8 or 9 get a +
        } else if (grade % 10 < 3) {
          lettergrade += '-';  // those ending in 0, 1, or 2 get a -
        }
      }
    }

    cout << lettergrade << endl;
  }

  return 0;
}
