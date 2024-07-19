
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using V = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}
const ll N = 2e5 + 20;
    ll n, k;
    ll a[N];
ll bd = 0;
ll b1, b2;
ll dfs (ll i, V<ll> v, ll d) {
    if (i < 0) {
        if (v.size() >= 2) {
            bd = max(bd, d);
            if (bd == d) {
                b1 = v[0];
                b2 = v[1];
            }
            return 1;
        }
        return 0;
    }
    if((v.size()) <= 1) return 0ll;
    V<ll> a, b;
    for (ll j = 0; j < v.size(); j++) {
        if (v[j]&(1ll<<i)) a.pb(v[j]);
        else b.pb(v[j]);
    }
    ll p=0, q=0;
    if (a.size() == 1 && b.size()==1) {
        return dfs(i-1,v,d);
    }
    if(a.size() > 1)
        p = 1 + dfs (i-1, a, d + (1ll<<i));
    if(b.size() > 1)
        q = 1 + dfs (i-1, b, d + (1ll<<i));
    return max(p, q);
}

void solve() {
    bd = -1;
    cin >> n >>k;
    V<ll> v;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) v.pb(a[i]);
    dfs(k-1, v, 0);
    ll p1, p2;
    for (ll i = 0;i < n; i++) {
        if (a[i] == b1) {p1 = i;break;}
    }
    for (ll i = 0;i <n; i++) {
        if (i != p1 && a[i] == b2) {
            p2 = i;
            break;
        }
    }
    ll x = 0;
    for (ll i = 0; i < k; i++) {
        if (((1ll<<i)&b1) == ((1ll<<i)&b2)) {
            if (((1ll<<i)&b1) == 0) {
                x ^= (1ll<<i);
            }
        }
    }

    cout<<p1 + 1 << " " << p2 + 1 << " " << x  << '\n';
}
