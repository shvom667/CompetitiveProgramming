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
  t = 1;
  while (t--) solve();
}
void chmax(ll& a, ll b) {
  a = max(a, b);
}
void solve() {
  ll n;
  cin >> n;
  deque<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  if (n == 1) {
    cout << a[0] << "\n";
    return;
  }
  ll so, se;
  so = se = 0;
  for (ll i = 0; i <= n - 3; i++) {
    if(i&1)
      so += a[i];
    else
      se += a[i];
  }
  ll fans = 0;
  for (ll j = 1; j <= 2 * n; j++) {
    ll cur = 0;
    cur = so + a[n-1] + a[n-2];
    chmax(fans, cur);
    ll nse, nso;
    nso = se - a[n-3];
    nse = so + a[n-1];
    so = nso;
    se = nse;
    ll b = a.back();
    a.pop_back();
    a.push_front(b);
  }
  cout << fans << "\n";
}
