#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve() {
    return 0;
}
const ll MOD = 998244353;
auto bf (ll n, Vec<ll> a) {
    ll fans = 0;
    for (ll i = 0; i < (1ll << n); i++) {
        vector<ll> cur;
        for (ll bit = 0; bit < n; bit++) {
            if (i & (1ll << bit)) {
                cur.pb(a[bit]);
            }
        }
        vector<ll> cnt(n, 0);
        for (auto&x : cur) {
            cnt[x]++;
        }
        for (ll i = 0; i < n; i++) {
            if (i)
                cnt[i] = min(cnt[i-1], cnt[i]);
            fans += cnt[i];
            fans %= MOD;
        }
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll  i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto res = bf(n, a);
        cout << res << "\n";
    }
    return 0;
}
