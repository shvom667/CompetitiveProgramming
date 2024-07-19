
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
using pl = pair<ll, ll>;
void solve() {
    ll n, m;
    cin >> n >> m;
    ll f = 0;
    for (ll p = 1; p <= m; p++) {
        for (ll q = 1; q <= n && (p+q)*(p+q) <= n + m; q++) {
            if (gcd(p,q) == 1) {
                ll v1 = n / (p * (p + q));
                ll v2 = m / (q * (p + q));
                ll v3 = (n + m) / ((p+q)*(p+q));
                f += min({v1, v2, v3});
            }
        }
    }
    cout << f << '\n';
}
