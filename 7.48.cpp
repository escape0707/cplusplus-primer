#include "Sales_data.h"
std::string null_isbn("9-999-99999-9");
// ok: Sales_data(const std::string &);
Sales_data item1(null_isbn);
// ok: implicit conversion to string, then Sales_data(const std::string &);
Sales_data item2("9-999-99999-9");
// "explicit" won't change the result