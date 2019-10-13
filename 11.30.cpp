// pos is the return value of equal_range, which is a pair<map<Key, T>::iterator,
// map<Key, T>::iterator>
// pos.first is initially the lower_bound, then increased step by step
// pos.first->second is a map<Key, T>::mapped_type i.e. T
