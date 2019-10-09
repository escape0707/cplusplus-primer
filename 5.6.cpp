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
    string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
    // if failing grade, no need to check for a plus or minus
    // add plus or minus only if not already an A++
    if (60 <= grade && grade < 100)
      lettergrade += grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "";

    cout << lettergrade << endl;
  }
}
