#include "Query.h"

#include <memory>
#include <string>
#include <utility>

#include "ByKeyRange.h"
#include "QueryResult.h"
// #include "TextQuery.h"
// PCH warning: header stop not at file scope.  An IntelliSense PCH file was not
// generated.

using std::make_unique;
using std::string;

using Query = TextQuery::Query;
using QueryResult = TextQuery::QueryResult;

Query Query::parse(const string &pattern) {
  return Query(key_type(pattern));
}

QueryResult Query::eval(const TextQuery &text_query) const {
  return QueryResult(p_range_->rep(), text_query.get_file(),
                     p_range_->eval(text_query));
}

Query::Query(key_type &&key)
    : p_range_(make_unique<ByKeyRange>(std::move(key))) {}
