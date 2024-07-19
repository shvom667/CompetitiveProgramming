
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
ll ub(ll x, ll y) {
  return (x + y - 1) / y;
}
void solve() {
  ll a,b, c;
  cin >> a >> b >> c;
  if (c != a + 1) {
    cout << -1 << '\n';
    return;
  }
  ll x = log2(a + c);
  ll lft = a + c - pow(2, x) + 1;
  ll ulft = c - lft;
  if (b <= ulft) {
    cout << x << '\n';
    return;
  }
  b -= ulft;
  cout << x + ub(b,c) << '\n';
}
