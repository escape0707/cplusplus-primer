int main() {
  const int v2 = 0;           // top
  int v1 = v2;                // not
  int *p1 = &v1, &r1 = v1;    // not
  const int *p2 = &v2;        // low
  const int *const p3 = &v2;  // top + low
  const int &r2 = v2;         // low
}