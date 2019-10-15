#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>

using std::copy;
using std::cout, std::endl;
using std::ostream_iterator;
using std::stack;
using std::string;

int main() {
  // Parenthesized expression.
  string s("This is (Some (awesome)((((wooooooooo))))) and (ocxs) over");
  stack<char> stk;     // Stack to hold process result.
  unsigned count = 0;  // Counter for '('.

  for (char &c : s) {
    if (c == ')' && count) {
      --count;
      while (stk.top() != '(') {
        stk.pop();
      }
      // change the '(' to '#' to indicate that the expression was replaced
      stk.top() = '#';
    } else {
      if (c == '(') {
        ++count;
      }
      stk.push(std::move(c));
    }
  }


  string rev;  // Cached content of stack in reverse order
  rev.reserve(stk.size());
  // cache content of stack in reverse order
  while (!stk.empty()) {
    rev.push_back(stk.top());
    stk.pop();
  }

  // print result in original order
  copy(rev.crbegin(), rev.crend(), ostream_iterator<char>(cout));
  cout << endl;
}