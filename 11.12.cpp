#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin, std::cout, std::endl;
using std::pair;
using std::string;
using std::vector;

int main() {
	vector<pair<string, int>> pvec;
	string s;
	int i;
	while (cin >> s >> i) {
		pvec.emplace_back(s, i);
	}

	for (const pair<string, int> &p : pvec) {
		cout << p.first << ": " << p.second << endl;
	}
}
