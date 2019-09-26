#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main() {
  // store each line from a file in a vector<string>
  ifstream fin("a.in");
  vector<string> text;
  string line;
  while (getline(fin, line)) {
    text.push_back(line);
  }

  // use an istringstream to read each element of the vector a word at a time
  for (const string &elem : text) {
    istringstream iss(elem);
    string word;
    while (iss >> word) {
      cout << word;
    }
    cout << endl;
  }
}
