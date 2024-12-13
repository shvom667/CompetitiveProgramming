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

auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> ind(5e6 + 20);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]].pb(i);
    }
    vector<ll> g2;

    for (ll i = 1; i < (ll)5e6 + 20; i++) {
        if (ind[i].size() >= 4) {
            cout << "YES\n";
            for (ll j  = 0; j < 4; j++) {
                cout << ind[i][j] + 1 << " ";   
            }   cout << '\n';
            return;
        }
        if ((ll) ind[i].size() >= 2) {
            g2.push_back(i);
        }
    }



    if ((ll)g2.size() >= 2) {
        vector<ll> fans;

        fans.pb(ind[g2[0]][0]);
        fans.pb(ind[g2[1]][0]);
        fans.pb(ind[g2[0]][1]);
        fans.pb(ind[g2[1]][1]);
        cout << "YES\n";
        for (auto&x : fans) {
            cout << x + 1 << ' ';   
        }   cout << '\n';
        return;
    }



    if ((ll)g2.size() == 1) {
        ll sum = g2[0] + g2[0];
        for (ll i = 1; i <= 5e6; i++) {
            if (i == g2[0])continue;
            ll a = i, b = sum - i;
            if (a > 0 && b > 0) {
                if (ind[a].size() > 0 && ind[b].size() > 0) {
                    cout << "YES\n";
                    vector<ll> fans;
                    fans.pb(ind[g2[0]][0]);
                    fans.pb(ind[g2[0]][1]);
                    fans.pb(ind[a][0]);
                    fans.pb(ind[b][0]);
                    for (auto&x : fans) {
                        cout << x + 1 << ' ';   
                    }   cout << '\n';
                    return;
                }
            }
        }


        ll inf = -1e14;
        for(ll i = 1; i < (ll)ind[g2[0]].size(); i++) {
            a[ind[g2[0]][i]] = inf;
            inf *= 10;
        }
    }

    map<int, vector<pair<ll, ll>>> mp;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            mp[a[i] + a[j]].push_back({i,j});
            if (mp[a[i] + a[j]].size() >= 2) {
                vector<ll> fans;
                for (ll k = 0; k < 2; k++) {
                    fans.pb(mp[a[i]+a[j]][k].first);
                    fans.pb(mp[a[i]+a[j]][k].second);

                }
                cout << "YES\n";
                for (auto&x : fans) {
                    cout << x + 1 << ' ';   
                }   cout << '\n';
                return;
            }
        }
    }

    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
    }
    return 0;
}
