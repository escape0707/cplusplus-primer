#pragma once

#include <array>
#include <ostream>
#include <string>

// A class that has three unsigned members representing year, month, and day.
class Date {
  friend bool operator==(const Date &lhs, const Date &rhs);
  // Print the date in format of M/D/Y
  friend std::ostream &operator<<(std::ostream &os, const Date &d);

 public:
  // A constructor that takes a string representing a date, and handle a variety
  // of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900 and so on.
  explicit Date(const std::string &date);

 private:
  unsigned extract_month(const std::string &date);
  unsigned month, day, year;
  // The abbreviation of 12 months.
  const std::array<std::string, 12> month_abbr{"Jan", "Feb", "Mar", "Apr",
                                               "May", "Jun", "Jul", "Aug",
                                               "Sep", "Oct", "Nov", "Dec"};
};

bool operator!=(const Date &lhs, const Date &rhs);
