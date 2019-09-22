// no, when defining Sales_data object, we will meet errors like below:

// 7.38.cpp: In function ‘int main()’:
// 7.38.cpp:6:14: error: call of overloaded ‘Sales_data()’ is ambiguous
//     6 |   Sales_data data;
//       |              ^~~~
// 7.38.cpp:3:1: note: candidate: ‘Sales_data::Sales_data(std::istream&)’
//     3 | Sales_data::Sales_data(std::istream &is = std::cin) { read(is, *this); }
//       | ^~~~~~~~~~
// In file included from 7.38.cpp:1:
// Sales_data.h:24:3: note: candidate: ‘Sales_data::Sales_data(const string&)’
//    24 |   Sales_data(const std::string &s = "") : bookNo(s) {}
//       |   ^~~~~~~~~~