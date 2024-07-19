
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
const ll INF64 = 1e15;
void solve() {
  ll n, k;
  cin >> n >> k;
  Vec<ll> a(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(begin(a) + 1, end(a));
  ++k;
  deque<ll> pts;
  for (ll i = 1; i <= k; i++) {
    pts.pb(a[i]);
  }
  ll ml, mr;
  ml = pts.front(), mr = pts.back();
  for (ll i = k + 1; i <= n; i++) {
    pts.pop_front();
    pts.push_back(a[i]);
    if (mr - ml > pts.back() - pts.front()) {
      ml = pts.front(), mr = pts.back();
    }
  }
  cout << (ml + mr) / 2 << '\n';
}
