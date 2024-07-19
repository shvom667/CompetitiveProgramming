
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
  ll n, q;
  cin >> n >> q;
  ll d[q];
  ll p = n-1;
  for (ll i = 1; i <= n-1; i++) {
    cout << i << " " << i + 1 << "\n";
  }
  for (ll i = 0; i < q; i++) {
    cin >> d[i];
    if (d[i] == p) {
      cout << -1 << " " << -1 << " " << -1 << "\n";
    } else {
      cout << n << " " << p << " " << d[i] << "\n";
      p = d[i];
    }
  }
}
