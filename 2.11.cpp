extern double pi = 3.1416;  // definition
extern int ix = 1024;

int main() {
  extern int i;  // declares but does not define i
  int j;         // declares and defines j
  // extern double pi = 3.1416; // error

  int iy;
  extern int iz;
}