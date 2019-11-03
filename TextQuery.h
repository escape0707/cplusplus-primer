#ifndef TEXTQUERY
#define TEXTQUERY

#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class QueryResult;  // declaration for TextQuery::query's return type

class TextQuery {
 public:
  using shared_container_ptr = std::shared_ptr<std::vector<std::string>>;
  using key_type = shared_container_ptr::element_type::value_type;
  using line_no = shared_container_ptr::element_type::size_type;
  using map_type = std::map<key_type, std::shared_ptr<std::vector<line_no>>>;
  TextQuery(std::ifstream &fin);
  QueryResult query(const key_type &keyword) const;

 private:
  // pointer to shared container of text in fin
  shared_container_ptr file;
  map_type wm;  // map from word to shared container of corresponding ln
};

#include "QueryResult.h"

#endif
