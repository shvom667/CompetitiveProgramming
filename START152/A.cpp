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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto&x : a) {
        cin >> x;
    }
    sort(begin(a),end(a));
    if (n <= 3) {
        cout << 0 << "\n";
    } else {
        cout << min({a[n-3]-a[0], a[n-1]-a[2],a[n-2]-a[1]}) << '\n';
    }
}
