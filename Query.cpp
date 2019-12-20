#include "Query.h"

#include <string>
#include <utility>

#include "QueryResult.h"
// #include "TextQuery.h"
// PCH warning: header stop not at file scope.  An IntelliSense PCH file was not
// generated.

using std::pair;
using std::string;

using Query = TextQuery::Query;
using QueryResult = TextQuery::QueryResult;

Query::Query(const key_type &key) : key_(key) {}

QueryResult Query::eval(const TextQuery &text_query) const {
  pair<record_const_iterator, record_const_iterator> p =
      text_query.find_key(key_);
  return QueryResult(string(key_), text_query.get_file(), p.first, p.second);
}
