int main() {
  int *p = nullptr;
  if (p) // check p == nullptr
    ;
  if (*p) // check the int addressed by p == 0
    ;
  return 0;
}