// template <std::string::size_type height, std::string::size_type weight>
// That will do. But then height, and weight will be constexpr, and always go
// with the instantiation's type info. It's probably not good to store a mutable
// copy of them.

// I don't have a good use case for this class so I won't implement it for now.
