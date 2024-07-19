
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
    ll n, m;
    cin >> n >> m;
    ll f=0;
    for (ll b = 1; b <= m; b++) {
        for (ll q = 1; q * b <= n + m; q++) {
            ll sum = q * b;
            ll a = sum - b;
            if (a>n)continue;
            ll v = b * gcd(a,b);
            if (sum%v==0)
                f++;
        }
    }
    cout<<f-1<<'\n';
}
