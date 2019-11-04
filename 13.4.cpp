class Point {};

Point global;

Point foo_bar(Point arg /* 1 */) {
  Point local = arg/* 2 */, *heap = new Point(global/* 3 */);
  *heap = local; // operator=, AKA: copy-assignment operator
  Point pa[4] = {local/* 4 */, *heap/* 5 */};
  return *heap/* 6 */;
}
