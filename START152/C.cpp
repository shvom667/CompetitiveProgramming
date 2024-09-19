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

bool g(ll a, ll b, ll n) {
    if (min(a,b) == n/2 && max(a, b) == n - n/2) {
        return true;
    } 
    return false;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<vector<ll>> cnt(3,vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        cnt[v[i]][i] += 1;
        if (i) {
            cnt[0][i] += cnt[0][i-1];
            cnt[1][i] += cnt[1][i-1];
            cnt[2][i] += cnt[2][i-1];
        }
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;r--;
        bool ok = false;

        ll c0 = 0, c1 = 0, c2 = 0;
        c0 = cnt[0][r] - (l > 0 ? cnt[0][l-1] : 0);
        c1 = cnt[1][r] - (l > 0 ? cnt[1][l-1] : 0);
        c2 = cnt[2][r] - (l > 0 ? cnt[2][l-1] : 0);

        if (g(c0+c1, c2, r-l+1)) ok =true;
        if (g(c0+c2, c1, r-l+1)) ok =true;
        if (g(c1+c2, c0, r-l+1)) ok =true;
        if ((r-l+1)&1) ok = false;
        if (ok) {
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }   
}