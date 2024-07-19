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

ll ub (ll x, ll y) {
  return (x + y - 1) / y;
}
void solve() {
  ll n;
  cin >> n;
  Vec<ll>  a(n);
  ll p0 = 0;
  for (ll i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '1') a[i] = 1;
    else a[i] = 0;
  }
  ll s1 = count(begin(a), end(a), 1ll);
  Vec<ll> valid;
  if (s1 >= ub(n, 2)) {
    valid.pb(-1);
  }
  for (ll i = 0; i < n; i++) {
    if (a[i] == 0) p0++;
    else s1--;
    if (p0 >= ub(i+1,2) && s1 >= ub(n-i-1,2)) {
      valid.pb(i);
    }
  }
  for (auto&x : valid) x++;
  sort(begin(valid), end(valid), [&] (ll a, ll b){
      if (abs(n-2*a) < abs(n-2*b)) {
        return true;
      }
      if (abs(n-2*a) > abs(n-2*b)) {
        return false;
      }
      return a < b;
    });
  cout << valid[0] << "\n";
}

