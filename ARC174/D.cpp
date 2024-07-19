
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using Vec = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    t = 1;
    while(t--)solve();
}
struct p2 {
  ll F; ll S;
};
ll pow(ll a, ll x) {
  if (x == 0) return 1ll;
  ll res = 1;
  res = pow(a, x/2);
  res *= res;
  if (x&1) {
    res *= a;
  }
  return res;
}
void solve() {
  ll K = 10;
  Vec<p2> seg;
  p2 id;
  id.F=1, id.S=1;
  seg.pb(id);
  for (ll i = 1; i <= 9; i++) {
    id.F = pow(K,2*i)-2*pow(K,i);
    id.S = id.F;
    seg.pb(id);
    id.F = pow(K,2*i) - pow(K,i);
    id.S = pow(K, 2*i) + pow(K,i) - 1;
    seg.pb(id);
  }
  for (ll i = 0; i < seg.size(); i++)  {
    //cout << seg[i].F << " " << seg[i].S << "\n";
  }

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >>n;
    ll fans = 0;
    for (auto x : seg) {
      if (n >= x.F) {
        fans += min(n, x.S) - x.F + 1;
      }
    }
    cout << fans << "\n";
  }
}
