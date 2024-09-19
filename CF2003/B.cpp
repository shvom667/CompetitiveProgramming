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
    vector<ll> v(n);
    for(auto&x : v) {
        cin >> x;
    }
    sort(begin(v), end(v));

    cout << v[v.size() / 2] << '\n';
}