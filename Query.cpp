#include "Query.h"

#include <memory>
#include <string>
#include <utility>

#include "AndRange.h"
#include "ByKeyRange.h"
#include "NotRange.h"
#include "QueryResult.h"
// #include "TextQuery.h"
// PCH warning: header stop not at file scope.  An IntelliSense PCH file was not
// generated.

using std::make_shared;
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
    : p_range_(make_shared<ByKeyRange>(std::move(key))) {}

Query::Query(std::shared_ptr<LineNumberRange> &&p_range) : p_range_(p_range) {}

Query operator~(const Query &rhs) {
  return Query(make_shared<NotRange>(rhs.p_range_));
}

Query operator&(const Query &lhs, const Query &rhs) {
  return Query(make_shared<AndRange>(lhs.p_range_, rhs.p_range_));
}
