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
    auto ask = [&] (ll x, ll y) {
        cout << "? " << x << " " << y << endl;
        ll res;
        cin >> res;
        return res;
    };
    set<pair<ll, ll>> edge;
    for (ll i = 2; i <= n; i++) {
        ll l = 1, r = i;
        ll v = 1;
        while (true) {
            ll res = ask(v, i);
            if (res == v) {
                edge.insert({min(v, i), max(v, i)});
                break;
            } else {
                v = res;
            }
        }
    }
    assert((ll)edge.size() == n - 1);
    cout << "! ";
    for (auto& [a, b] : edge) {
        cout << a << " " << b << " ";
    }
    cout << endl;
}