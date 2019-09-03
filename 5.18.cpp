#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  do {
    int v1, v2;
    cout << "Please enter two numbers to sum: ";
    if (cin >> v1 >> v2) {
      cout << "Sum is: " << v1 + v2 << endl;
    }
  } while (cin);

  int ival;
  do {
    // ...
  } while (ival = get_response());

  int ival;
  do {
    // ...
  } while (ival = get_response());
}
