class Base {};

struct Pub_Derv : public Base {};

struct Priv_Derv : private Base {};

struct Prot_Derv : protected Base {};

struct Derived_from_Public : public Pub_Derv {};

struct Derived_from_Private : public Priv_Derv {};

struct Derived_from_Protected : public Prot_Derv {};

int main() {
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Public dd1;
  Derived_from_Private dd2;
  Derived_from_Protected dd3;

  Base *p = &d1;  // ok: Base part of Pub_Derv is public
  // p = &d2;  // error: Base part of Priv_Derv is private
  // p = &d3;  // error: Base part of Prot_Derv is protected because
  // Derived_from_* classes public derive from their base classes, they result
  // the same answer as the first three assignments for the same reason
  p = &dd1;
  // p = &dd2;
  // p = &dd3;
}
