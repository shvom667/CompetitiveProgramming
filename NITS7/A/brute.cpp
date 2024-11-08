#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif


mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}


auto solve() {
    vector<ll> dx = {1, -1, 0, 0};
    vector<ll> dy = {0, 0, 1, -1};
    ll n,m,r1,r2;
    cin >> n >> m >> r1 >> r2;
    ll fans = 1e10;
    for (ll x1 = 1; x1 <= n; x1++) {
        for (ll y1 = 1; y1 <= m; y1++) {
            for (ll x2 = 1; x2 <= n; x2++) {
                for (ll y2 = 1; y2 <= m; y2++) {
                    
                    vector<vector<ll>> g(n + 1, vector<ll> (m + 1, 0));

                    if (x1 - r1 >= 1 && y1 - r1 >= 1 && x1 + r1 <= n &&  y1 + r1 <= m) {
                        if (x2 - r2 >= 1 && y2 - r2 >= 1 && x2 + r2 <= n &&  y2 + r2 <= m) {
                            for (ll i = 1; i <= n; i++) {
                                for (ll j = 1; j <= m; j++) {
                                    if (abs(i - x1) + abs(j - y1) <= r1) g[i][j]++;
                                    if (abs(i - x2) + abs(j - y2) <= r2) g[i][j]++;
                                }

                            }
                            bool ok = true;
                            for (ll i = 1; i <= n; i++) {
                                for (ll j = 1; j <= m; j++) {
                                    if (g[i][j] > 1) {
                                        ok = false;
                                    }
                                }
                            }

                            g = vector<vector<ll>> (n + 1, vector<ll> (m + 1, 0));
                            for (ll i = 1; i <= n; i++) {
                                for (ll j = 1; j <= m; j++) {

                                    if (abs(i - x1) + abs(j - y1) <= r1) g[i][j] = 1;
                                    if (abs(i - x2) + abs(j - y2) <= r2) g[i][j] = 2;
                                }
                            }


                            for (ll i = 1; i <= n; i++) {
                                for (ll j = 1; j <= m; j++) {
                                    for (ll k = 0; k < 4; k++) {
                                        ll ni, nj;
                                        ni = i + dx[k], nj = j + dy[k];
                                        if (ni >= 1&& ni <= n && nj >= 1 && nj <= m) {
                                            if (g[i][j] == 1 && g[ni][nj] == 2) ok = false;
                                        }
                                    }
                                }
                            }

                            if (ok) {
                                if (x1 + y1 + x2 + y2 == 21) {
                                    dbg(x1, y1, x2, y2);
                                }
                                fans = min(fans, x1 + y1 + x2 + y2);
                            }
                        }
                    }

                }
            }
        }
    }

    return fans >= 1e10 ? -1 : fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    auto res = solve();
    cout << res << '\n';
    return 0;
}
