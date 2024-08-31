#include <bits/stdc++.h>
using namespace std;

using ll = int;
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

ll solve(ll N, ll K, Vec<ll> &A) {
    Vec<ll> g[min(N,K)];
    for (ll i = 0; i < N; i++) {
        g[i%K].pb(A[i]);
    }

    ll sz = min(N, N%K>0?N%K:K);

    auto cond = [&] (ll x) {
        ll ysz = g[sz-1].size();
        int b[sz][ysz], res[sz][ysz];
        assert(sz * ysz <= N);
        for (ll i = 0; i < sz; i++) {
            for (ll j = 0; j < ysz; j++) {
                b[i][j] = g[i][j] >= x;
            }
        }
        for (ll j = 0; j < ysz; j++) {
            res[0][j] = b[0][j];
        }
        for (ll i = 1; i < sz; i++) {
            for (ll j = 1; j < ysz; j++) {
                chmax(res[i-1][j], res[i-1][j-1]);
            }
            for (ll j = 0; j < ysz; j++) {
                res[i][j] = res[i-1][j] + b[i][j];
            }
        }
        ll f = *max_element(res[sz-1], res[sz-1] + ysz);
        return f >= (sz + 2) / 2;
    };
    Vec<ll> B = A;
    sort(begin(B),end(B));
    ll l = 0, r = N-1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (cond(B[mid])) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return B[r];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        Vec<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, k, a) << "\n";
    }
}
