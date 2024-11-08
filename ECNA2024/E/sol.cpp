#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

 
auto bf() {

    vector<ll> v;
    ll n = 10;
    for (ll i = 1; i <= n; i++) v.push_back(i);
    assert((ll)v.size() == n);

    ll den = 0;
    ll num = 0;
    set<vector<ll>> s;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            vector<ll> u;
            for (ll k = 0; k < n; k++) {
                if (k != i && k != j) {
                    u.push_back(v[k]);
                }
            }
            // dbg(u);
            ll sq = 4;
            do {
                bool ok = true;
                assert((ll)u.size() == 2 * sq);
                for (ll i = 0; i < 2 * sq; i+=2) {
                    // u[i], u[i + 1]
                    ll cnt = 0;
                    cnt += (u[i] >= 1 && u[i] <= 4);
                    cnt += (u[i + 1] >= 1 && u[i + 1] <= 4);
                    if (cnt != 1) {
                        ok = false;
                    }
                }
                if (ok) {
                    dbg(u);
                    s.insert(u);
                    num++;
                }

                den++;
            } while (next_permutation(begin(u), end(u)));
        }
    }
    dbg(s.size());

    cout << num << " " << den << "\n";
}

const ll M = 50;
ll C[M][M];
ll F[M];

ll gcd(ll x, ll y) {
    if (min(x, y) == 0) return max(x, y);
    return __gcd(x, y);
}

void init() {
    C[0][0] = 1;
    for (ll i = 1; i < M; i++) {
        C[i][0] = 1;
    }

    for (ll i = 1; i < M; i++) {
        for (ll j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    F[0] = 1;
    for (ll i = 1; i < M; i++) {
        F[i] = F[i - 1] * i;
    }

}

void solve() {
    ll N, M, P;
    cin >> N >> M >> P;

    ll dpn[N + 1][P + 1];
    ll dpd[N + 1][P + 1];

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j < i; j++) {
            dpn[i][j] = 0;
        }
    }

    dpn[1][1] = 2;
    dpd[1][1] = M;
    ll g = gcd(dpn[1][1], dpd[1][1]);

    dpn[1][1] /= g;
    dpd[1][1] /= g;


    for (ll i = 1; i <= N; i++) {

    }

}   

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    init();
    exit(0);
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
