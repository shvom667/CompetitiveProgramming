
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
  ll n, m, k;
  cin >> n >> m >> k;
  if (k + ub(n,m) >= n) {
    cout << "NO\n";
    return;
  } else {
    cout << "YES\n";
    return;
  }
}
