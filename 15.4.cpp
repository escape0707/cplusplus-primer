class Base {};
// class Derived1 : public Derived1 {};, incorrect, Derived1 is incomplete
class Derived2 : private Base {};  // ok
// class Derived3 : public Base;  // incorrect, derivation list can't appear in
// declaration
