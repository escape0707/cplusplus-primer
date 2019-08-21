int main() {
  // int i, *const cp;
  int i, *const cp = nullptr;

  // int *p1, *const p2;
  int *p1, *const p2 = nullptr;

  // const int ic, &r = ic;
  const int ic = 0, &r = ic;

  // const int &const r2;
  const int &const r2 = 0;

  // const int *const p3;
  const int *const p3 = nullptr;

  const int *p;

  i = ic;

  // p1 = p3;

  // p1 = &ic;

  // p3 = &ic;

  // p2 = p1;

  // ic = *p3;
}