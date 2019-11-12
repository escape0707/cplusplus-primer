//  destroy(first, last) > while() > for_each()

#include <algorithm>
#include <memory>

#include "StrVec.h"

using std::destroy, std::destroy_at;
using std::for_each;

// void StrVec::free() {
//   if (elements) {
//     destroy(elements, first_free);
//     Alloc_traits::deallocate(alloc, elements, capacity());
//   }
// }

// void StrVec::free() {
//   if (elements) {
//     while (first_free != elements) {
//       Alloc_traits::destroy(alloc, --first_free);
//       // destroy_at(--first_free);
//     }
//     Alloc_traits::deallocate(alloc, elements, capacity());
//   }
// }

void StrVec::free() {
  if (elements) {
    for_each(elements, first_free,
             [&](reference elem) { Alloc_traits::destroy(alloc, &elem); });
    Alloc_traits::deallocate(alloc, elements, capacity());
  }
}
