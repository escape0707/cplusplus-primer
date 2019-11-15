#include <cctype>
#include <cstdlib>
#include <ostream>
#include <stdexcept>
#include <tuple>

#include "Date.h"

using std::invalid_argument;
using std::isdigit;
using std::ostream;
using std::stoi;
using std::string;
using std::strtol;
using std::tie;

Date::Date(const string &date) {
  // deduce month from date
  month = extract_month(date);
  // deduce day from date, starting off the first delimiter
  string::size_type pos = date.find_first_of(" ,/");
  // throw if no proper delimiter found
  if (pos == string::npos) {
    throw invalid_argument("No delimiter between month and day.");
  }
  // since std::stoi() don't support converting from a pos other than begin,
  // we can use the underlying std::strtol() here
  day = strtol(date.c_str() + pos + 1, nullptr, 10);
  if (day == 0) {
    // if conversion failed, throw
    throw invalid_argument("Unexpected representation for day.");
  }

  // deduce year from date, starting off the second delimiter
  pos = date.find_first_of(" ./", pos + 1);
  // throw if no proper delimiter found
  if (pos == string::npos) {
    throw invalid_argument("No delimiter between day and year.");
  }
  // convert year from the string
  year = strtol(date.c_str() + pos + 1, nullptr, 10);
  if (year == 0) {
    // if conversion failed, throw
    throw invalid_argument("Unexpected representation for year.");
  }
}

unsigned Date::extract_month(const string &date) {
  if (isdigit(date[0])) {  // if date starts with digits
    return stoi(date);     // return first digits as month
  }
  // if date is too short as a string representation of month
  if (date.length() < 3) {
    throw invalid_argument("Data is too short for deducing month from it.");
  }
  // check if date starts with a month abbreviation
  for (unsigned i = 0; i < 12; ++i) {
    // string::starts_with available since C++20
    /* if (date.start_with(month_abbr[month])) { */
    // if date starts with a month, return month number
    if (date.compare(0, month_abbr[i].length(), month_abbr[i])) {
      return i + 1;
    }
  }
  // if date doesn't start with any month
  throw invalid_argument("Missing valid month data.");
}

bool operator==(const Date &lhs, const Date &rhs) {
  return lhs.month == rhs.month && lhs.day == rhs.day && lhs.year == rhs.year;
}

bool operator!=(const Date &lhs, const Date &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Date &lhs, const Date &rhs) {
  return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}

bool operator>(const Date &lhs, const Date &rhs) {
  return rhs < lhs;
}

bool operator<=(const Date &lhs, const Date &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const Date &lhs, const Date &rhs) {
  return !(lhs < rhs);
}

ostream &operator<<(ostream &os, const Date &d) {
  return os << d.month << '/' << d.day << '/' << d.year;
}
