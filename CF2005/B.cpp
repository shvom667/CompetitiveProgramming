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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> b(m), a(q);
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (ll i = 0; i < q; i++) {
        cin >> a[i];
    }
    sort(begin(b),end(b));
    for(auto& x: a) {
        auto it = upper_bound(begin(b),end(b),x);
        if (it == end(b)) {
            cout << n - b.back() << "\n";
            continue;
        }   
        if (it == begin(b)) {
            cout << b[0] - 1 << "\n";
            continue;
        }
        auto jt = it;
        jt--;
        cout << (*it - *jt) / 2 << "\n";

    }

}