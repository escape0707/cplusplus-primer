// see Account.h

#include "Account.h"

int main() {
  double r;
  r = Account::rate();  // access a static member using the scope operator

  Account ac1;
  Account *ac2 = &ac1;

  // equivalent ways to call the static member rate function
  r = ac1.rate();   // through an Account object or reference
  r = ac2->rate();  // through a pointer to an Account object
}
