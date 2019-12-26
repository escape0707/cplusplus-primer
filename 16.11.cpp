template <typename elemType>
class ListItem;

template <typename elemType>
class List {
 public:
  List<elemType>();
  List<elemType>(const List<elemType> &);
  List<elemType> &operator=(const List<elemType> &);
  ~List();
  // error: use of class template 'ListItem' requires template arguments;
  // argument deduction not allowed in function prototype
  // void insert(ListItem *ptr, elemType value);
  void insert(ListItem<elemType> *ptr, elemType value);

 private:
  // error: use of class template 'ListItem' requires template arguments;
  // argument deduction not allowed in non-static class member
  ListItem<elemType> *front, *end;
};
