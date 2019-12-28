// (a): illegal, each template parameter must be preceded with `typename` or
// `class`
template <typename T, typename U, typename V>
void f1(T, U, V);
// (b): illegal, `T` is a typename, moreover, can't redeclare template
// parameter in a template
template <typename T>
T f2(int &i);
// (c): illegal, inline must be placed after template parameter list
template <typename T>
inline T foo(T, unsigned int *);
// (d): illegal, missing return type
template <typename T>
void f4(T, T);
// (e): legal, although template parameter hides that typedef
