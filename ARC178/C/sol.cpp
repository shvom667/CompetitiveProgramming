#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll N = 2e5 + 20;
const ll inf = 1e18;
ll dp[N];

auto solve() {
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll>v;
    v.pb(l-1);
    while(v.back()-2>0){
        v.pb(v.back()-2);
    }
    dbg(v);

    ll k = v.size();
    for (ll i = 1; i < k; i++) {
        v[i] += v[i - 1];
    }
    dbg(v);

    for(ll i=1;i<N;i++){
        for(ll j=0;j<v.size();j++){
            if(i-v[j]>=0) {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            } else {
                break;
            }
        }
    }

    for(auto&x:a){
        cout<<(dp[x]==inf?-1:dp[x])<<"\n";
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i=1;i<N;i++)dp[i]=inf;

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
