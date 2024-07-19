
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
    cin>>t;
    while(t--)solve();
}

void solve() {
  ll n;
  cin >> n;
  ll a[n];
  ll b[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  reverse((b), (b+n));
  Vec<ll> r;
  for (ll i = 0, s = 0; i < n; i++) {
    while (b[i] > s) {
      s++;
      r.pb(n-i);
      if(r.size() > n) {
        cout << "NO\n";
        return;
      }
    }
  }
  bool ok = true;
  for (ll i = 0; i < n; i++) {
    if (a[i] != r[i]) ok = false;
  }
  if (!ok) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
