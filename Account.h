#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
 public:
  static constexpr int period = 30;  // period is a constant expression
  static double rate() { return interestRate; }
  static void rate(double newRate) { interestRate = newRate; }

  void calculate() { amount += amount * interestRate; }

 private:
  static constexpr double initRate() { return 1.; }
  static inline double interestRate = initRate();
  std::string owner;
  double amount;
  double daily_tbl[period];
};

#endif
