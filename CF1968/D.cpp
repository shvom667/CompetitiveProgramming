#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i32 int
#define pb push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x.size())
#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32)(n) - 1; i >= 0; --i)

template <typename T>
using Vec = vector<T>;
template<typename T>
vector<T> PrefixSum(vector<T> X) {
    ll n = X.size();
    vector<T> ret(n, 0);
    REP (i, n) {
        ret[i] = X[i];
        if (i > 0) ret[i] += ret[i - 1];
    }
    return ret;
}
template<typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}
template<typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}

void solve() {
    ll n, k, pa, pb;
    cin >> n >> k >> pa >> pb;
    ll p[n+1], a[n+1];
    Vec<ll> adj[n+1];;f
    for(ll i = 1; i <= n; i++) {
        cin >> p[i];
        adj[i].pb(p[i]);
    }
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll sa = 0, sb = 0;

    for (ll j = 0, mf = k, sum=0; j <= min(2*n,k); j++) {
        chmax(sa, sum + a[pa]*mf);

        // Update part
        sum += a[pa];
        pa = p[pa];
        mf--;
    }

    for (ll j = 0, mf = k, sum=0; j < min(2*n,k); j++) {
        chmax(sa, sum + a[pa]*mf);

        // Update part
        sum += a[pa];
        pa = p[pa];
        mf--;
    }

    for (ll j = 0, mf = k, sum=0; j < min(2*n,k); j++) {
        chmax(sb, sum + a[pb]*mf);

        // Update pbrt
        sum += a[pb];
        pb = p[pb];
        mf--;
    }
    

    if (sa == sb) {
        cout << "Draw" << '\n';
    } if (sa > sb) {
        cout << "Bodya" << '\n';
    } else {
        cout << "Sasha" << '\n';
    }
}

int main() {

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
