#include <cctype>
#include <cstdlib>
#include <exception>
#include <ostream>

#include "Date.h"

using std::invalid_argument;
using std::isdigit;
using std::ostream;
using std::stoi;
using std::string;
using std::strtol;

Date::Date(const string &date) {
  if (date.empty() || date.length() < 3) {
    throw invalid_argument("Input date is too short.");
  }

  // deduce month from date
  if (isdigit(date[0])) {  // if date starts with digits
    month = stoi(date);    // save first digits as month
  } else {                 // else, check if date starts with months' abbr
    for (month = 0; month < 12; ++month) {
      // string::starts_with available since C++20
      // if (date.start_with(month_abbr[month])) {

      // if date starts with a month
      if (!date.compare(0, month_abbr[month].length(), month_abbr[month])) {
        break;
      }
    }

    // if date doesn't start with a month
    if (month == 12) {
      throw invalid_argument("Missing valid month data.");
    }
    // else, calculate which month date means
    ++month;
  }

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

ostream &operator<<(ostream &os, const Date &d) {
  return os << d.month << '/' << d.day << '/' << d.year;
}