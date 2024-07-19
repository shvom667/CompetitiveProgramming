
#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
const ll N = 2*262144+10;
void solve() {
    ll n;
    cin >> n;
    ll a[n+1];
    ll p[n+1];
    a[0]=0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll m = *max_element(a, a + n);
    ll fans=0;
        Vec<ll> u(N, 0);
    for (ll i = 0; i <= 726; i++) {
        ll sq = i * i;
        if (sq > 2 * m) break;
        p[0]=0;
        for (ll i = 0; i <= n; i++)
            p[i] = a[i];
        Vec<ll> used;
        u[0]++;
        for (ll i = 1; i <= n; i++) {
            p[i] = (p[i] ^ p[i-1]);
            ll v = sq ^ p[i];
            fans += u[v];
            u[p[i]]++;
            used.pb(p[i]);
        }
        used.pb(0);
        for (auto&x : used)
            u[x]=0;
    }
    cout << (n*(n+1))/2-fans<<'\n';
}
