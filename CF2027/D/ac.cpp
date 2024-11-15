#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1, 0), b(m + 1, 0), p(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll j = 1; j <= m; j++)
        cin >> b[j];
    for (ll i = 1; i <= n; i++) {
        p[i] = a[i];
        p[i] += p[i - 1];
    }

    ll dp[n + 1][m + 1];
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= m; j++)
            dp[i][j] = INF;

    for (ll j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1;  j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            if (p[i - 1] < p[i] - b[j]) continue;
            ll L = 0, R = i;
            while (L <= R) {
                ll mid = L + (R - L) / 2;
                if (p[mid] >= p[i] - b[j]) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
            dp[i][j] = min(dp[L][j] + m - j, dp[i][j]);
        }
    }

    ll op[n + 1][m + 1];
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= m; j++)
            op[i][j] = 0;

    for (ll j = 0; j <= m; j++) {
        op[0][j] = 1;
    }

    for (ll j = 1; j <= m; j++) {

        map<ll,vector<pair<ll, ll>>> mp;

        mp[dp[0][j]].push_back({op[0][j], 0});
        for (ll i = 1; i <= n; i++) {

            if (dp[i][j] == dp[i][j - 1]) {
                op[i][j] += op[i][j - 1];
                op[i][j] %= MOD;
            }

            if (p[i - 1] >= p[i] - b[j]) {
                ll L = 0, R = i;
                while (L <= R) {
                    ll mid = L + (R - L) / 2;
                    if (p[mid] >= p[i] - b[j]) {
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }

                if (mp.find(dp[i][j] + j - m) != mp.end()) {
                    if (mp[dp[i][j] + j - m].back().second >= L) {
                        ll l = 0, r = mp[dp[i][j] + j - m].size() - 1;
                        while (l <= r) {
                            ll mid = l + (r - l) / 2;
                            if (mp[dp[i][j] + j - m][mid].second >= L) {
                                r = mid - 1;
                            } else {
                                l = mid + 1;
                            }
                        }
                        ll sum = mp[dp[i][j] + j - m].back().first;
                        if (l > 0) {
                            sum -= mp[dp[i][j] + j - m][l - 1].first;
                        }
                        sum %= MOD;
                        sum += MOD;
                        sum %= MOD;
                        op[i][j] += sum;
                        op[i][j] %= MOD;
                    }
                }

                // for (ll k = L; k <= i - 1; k++) {
                //     if (dp[k][j] == dp[i][j] + j - m) {
                //         op[i][j] += op[k][j];
                //     }
                // }
            }
            if (mp.find(dp[i][j]) != mp.end()) {
                assert(mp[dp[i][j]].size() >= 1);
                mp[dp[i][j]].pb({(op[i][j] + mp[dp[i][j]].back().first)%MOD , i});
            } else {
                mp[dp[i][j]].pb({op[i][j], i});
            }
        }
    }

    return make_pair(dp[n][m], op[n][m]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        if (res.first >= 1e15) {
            cout << -1 << "\n";
        } else {
            cout << res.first << " " << res.second << "\n";
        }
    }
    return 0;
}
