#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

#define fastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

void chmax(ll &a, ll b){
    a = max(a, b);
}


ll MAXN;

vector<ll> fen;

void update(ll i, ll delta) {
    while (i < MAXN) {
        fen[i] += delta;
        i += i&-i;
    }
}

ll sum(int i) {
    ll res = 0;
    while (i>0) {
        res += fen[i];
        i -= i&-i;
    }
    return res;
}

ll query(ll l, ll r) {
    return sum(r) - sum(l-1);
}
vector<ll> hen;

void update_(ll i, ll delta) {
    while (i < MAXN) {
        hen[i] += delta;
        i += i&-i;
    }
}

ll sum_(int i) {
    ll res = 0;
    while (i>0) {
        res += hen[i];
        i -= i&-i;
    }
    return res;
}

ll query_(ll l, ll r) {
    return sum_(r) - sum_(l-1);
}

auto solve() {

    ll fans=0;
    ll n, m;
    cin >> n >> m;
    vector<ll> r(n + 1); for (ll i = 1; i <= n; i++) cin >> r[i];
    vector<vector<ll>> dp(m + 3, vector<ll> (m + 3, 0));
    ll c0 = 0;
    fen = vector<ll> (m + 3, 0);
    hen = vector<ll> (m + 3, 0);
    MAXN = m + 3;
    for (ll i = n; i >= 1; i--) {
        if (r[i] == 0) {
            ll j = m - c0;
            for (ll x = 0; x <= j; x++) {
                chmax(dp[j][x], dp[j + 1][x]
                    + query(0, x)
                    + query_(0, j-x)
                    );
                chmax(dp[j][x], dp[j + 1][x + 1]
                    + query(0, x)
                    + query_(0, j - x)
                    );
            }

            c0++;
            fen = vector<ll> (m + 3, 0);
            hen = vector<ll> (m + 3, 0);
        } else {
            if (r[i] < 0) update_(abs(r[i]), 1);
            if (r[i] > 0) update(abs(r[i]), 1);
        }
    }
    fans = max(dp[1][0], dp[1][1]);
    return fans;
}

int main() {
    fastIO();
    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
