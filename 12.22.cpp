// as of 2019 and std=c++17, we use this method on stackoverflow to avoid code
// duplication between const and non-const version of iterator:
// https://stackoverflow.com/a/49425072/5366367
// but so far readers still have not learned template, so we just implement a
// duplication without considering operator== and copy/conversion from another
// iterator. yes, just like we are targeting a const StrBlob from the start and
// no StrBlobPtr class has even be defined.
// and two pointer class should be defined inside StrBlob as nested class, too.

// see ConstStrBlobPtr.h & ConstStrBlobPtr.cpp
