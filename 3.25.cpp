#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  // count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
  vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
  for (unsigned grade; cin >> grade;) { // read the grades
    if (grade <= 100) {//handle only valid grades
      ++*(scores.begin() + grade / 10);
    }
  }
  for (const auto &cnt : scores) {
    cout << cnt << ' ';
  }
  cout << endl;


}
