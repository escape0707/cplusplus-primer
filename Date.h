#ifndef DATE_H
#define DATE_H

#include <array>
#include <ostream>
#include <string>

// A class that has three unsigned members representing year, month, and day.
class Date {
  friend std::ostream &operator<<(std::ostream &os, const Date &d);

 public:
  // A constructor that takes a string representing a date, and handle a variety
  // of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900 and so on.
  explicit Date(const std::string &date);

 private:
  unsigned month, day, year;
  // The abbreviation of 12 months.
  const std::array<const std::string, 12> month_abbr{
      "Jan", "Feb", "Mar", "Apr", "May", "Jun",
      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
};

// Print the date in format of M/D/Y
std::ostream &operator<<(std::ostream &os, const Date &d);

#endif