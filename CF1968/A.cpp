
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
    ll x;
    cin >> x;
    ll best = 0;
    ll ba = -1;
    for (ll y = 1;  y < x; y++) {
        ll cur = gcd(x,y) + y;
        if (cur > best) {
            best = cur;
            ba = y;
        }
    }
    cout << ba << '\n';
}
