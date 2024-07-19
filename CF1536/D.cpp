
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
const ll inf = 1e18;

void solve() {
  ll n, mid;
  bool ok = true;
  cin >> n;
  deque<ll> lft, rht;
  lft.pb(-inf), rht.pb(inf);
  cin >> mid;
  for (ll i = 2; i <= n ;i++) {
    ll median;
    cin >> median;
    if (median==mid)continue;
    if (median<mid) {
      if (median < lft.back())
        ok = false;
      rht.push_front(mid);
      mid = median;
      if (lft.back() == mid) lft.pop_back();
    }
    if (median>mid) {
      if (median > rht.front())
        ok = false;
      lft.pb(mid);
      mid = median;
      if (rht.front() == mid)
        rht.pop_front();
    }
  }
  if (ok) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}
