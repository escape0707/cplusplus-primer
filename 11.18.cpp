#include <map>
#include <string>

using std::map;
using std::string;

int main() {
  map<string, size_t> words_count;
  map<string, size_t>::const_iterator map_it = words_count.cbegin();
}