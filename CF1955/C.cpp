
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

void solve() {
  ll n, k;
  cin >> n >> k;
  deque<ll> a(n);
  for (auto& x : a)
    cin >> x;
  ll dl, dr;
  dl = (k + 1) / 2;
  dr = k - dl;
  while (!a.empty() && dr > 0) {
    ll b = a.back();
    a.pop_back();
    if (dr >= b) {
      dr -= b;
    } else {
      a.pb(b-dr);
      dr = 0;
    }
  }
  while (!a.empty() && dl > 0) {
    ll f = a.front();
    a.pop_front();
    if (dl >= f) {
      dl -= f;
    } else {
      a.pb(f-dl);
      dl = 0;
    }
  }
  cout << n - a.size() << '\n';
}
