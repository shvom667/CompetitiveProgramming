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
const ll INF = 1e18;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), p(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
        if (i) {
            p[i] += p[i-1];
        }
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        if (b[i] < i) {
            b[i] = i;
        }
    }
    vector<ll> dp(n, 0);
    vector<ll> pval(n, 0);
    dp[0] = p[b[0]] - p[0];
    pval[0] = dp[0] - p[b[0]];

    multiset<ll> ms;

    ms.insert(dp[0]-p[b[0]]);

    deque<ll> dq(n);
    for(ll i = 0; i < n; i++) {
        dq[i] = i;
    }
    sort(begin(dq),end(dq),[&](ll x, ll y){
        return b[x] < b[y];
    });

    for (ll i = 1; i < n; i++) {
        
        while (!dq.empty()  && b[dq.front()] < i) {
            ll f = dq.front();
            ms.erase(ms.find(dp[f] - p[b[f]]));
            dq.pop_front();
        }
        dp[i] = ms.empty() ? -INF :  (*ms.rbegin()) - a[i] + p[b[i]];
        
        ms.insert(dp[i] - p[b[i]]);
        
    }
    ll fans = a[0];
    for (ll i = 0; i < n; i++) {
        fans = max(fans, dp[i]);
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
