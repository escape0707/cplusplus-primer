// as we process lines in a increasing order, we only need to check for
// situation where a word occurs multiple times on the same line. we skip
// appending line numbers for those conditions and we are golden to use vector
// instead.

// vector is faster in time and smaller in data size so i think vector approach
// is better.