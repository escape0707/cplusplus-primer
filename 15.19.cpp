// it's okay for every class (say D) directly derived from a base class
// (say B), as the base class B is always accesible from within the directly
// derived class D
//
// for the secondarily derived classes (say DD), if its base class D is derived
// privately from D's base class B, then it's an error as the B part is a
// private part of D

class Base {
  void memfcn(Base &b) { b = *this; }
};

struct Pub_Derv : public Base {
  void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
  void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
  // void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
  void memfcn(Base &b) { b = *this; }
};
