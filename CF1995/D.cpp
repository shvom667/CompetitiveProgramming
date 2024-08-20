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
const ll M = (1<<18) + 5;
ll n, N, K, C;
char S[M];
ll P[18][M];
bool B[M];
void solve() {
    cin >> n >> C >> K;

    for (ll i = 0; i < (1<<C); i++) {
        B[i] = false;
        for (ll j = 0; j < C; j++) {
            P[j][i] = 0;
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < C; j++) {
            P[j][i] = 0;
        }
    }

    for(ll i = 0; i < n; i++) {
        cin >> S[i];
        P[S[i] - 'A'][i]=1;
        for(ll j = 0; j < C; j++) {
            if (i > 0) {
                P[j][i] += P[j][i-1];
            }
        }
    }

    for (ll i = 0; i + K - 1 < n; i++) {
        ll v = 0;
        for (ll j = 0; j < C; j++) {
            if (P[j][i+K-1]-(i>0?P[j][i-1]:0ll) == 0) {
                v ^= (1ll<<j);
            }
        }
        B[v] = true;
    }
    
    for (ll b = C; b >= 0; b--) {
        for (ll i = 0; i < (1ll<<C); i++) {
            if (__builtin_popcount(i) == b) {
                for (ll j = 0; j < C; j++) {
                    if ((i&(1ll<<j)) == 0) {           
                        B[i] = (B[i] or B[i^(1ll<<j)]);
                    }
                }
            }
        }
    }
    ll last = S[n-1] - 'A';
    ll fans = 18;
    for (ll i = 0; i < (1 << C); i++) {
        if (! B[i] and (i&(1ll<<last))!=0) 
            fans = min(fans, (ll)__builtin_popcount(i));
    }
    cout << fans << "\n";
}

int main() {

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

