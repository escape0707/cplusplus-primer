// see Query.h & Query.cpp.
// Note: My Query class is not the same as the book describes, it not a wrapper
// class to a shared_ptr. It intends to be a interface class to a shared_ptr to
// a Range class (see below). But I don't know a clean way to use "virtual
// return type" in a C++ virtual function. So unless I define a similar
// construction for the Range class's Iterator type, I can't return a pair of
// memory efficent STL container like iterator to give access a Query_base's
// data. I'll leave that for later and maybe until C++20's <ranges> officially
// come out.

// see LineNumberRange.h & LineNumberRange.cpp for my replacement class for
// Query_base
// Note: this class tends to cut off the overhead of creating and copying
// QueryResult of each Query::eval by use iterator to eval each line_no
// separately in a "online" way. But I'll leave that implementation for later.

// And a pattern intepreter is not finished, too. When testing Query class, make
// sure to make Query(const std::string &) public.