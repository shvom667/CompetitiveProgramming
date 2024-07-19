
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
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  Vec<ll> v;
  v.pb(a[0]);
  for (ll i = 1; i < n; i++) {
    if (a[i] >= v.back()) {
      v.pb(a[i]);
    }
    else {
      v.pb(1);
      v.pb(a[i]);
    }
  }
  cout << v.size() << "\n";
  for (auto& x : v) {
    cout << x << " ";
  } cout << "\n";
}
