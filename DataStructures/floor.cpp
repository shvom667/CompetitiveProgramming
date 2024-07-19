ll lb (ll x, ll y) {
  assert(y);
  if (x==0) return 0;
  if ((x>0&&y>0) || (x<0&&y<0)) {
    return x/y;
  }
  return x/y-1;
}
