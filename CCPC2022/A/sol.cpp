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
 
auto solve() {
    ll n;
    cin >> n;
    map<string, bool> champ;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 5; j++) {
            string s;
            cin >> s;
            champ[s] = true;
        }
    }

    ll m;
    cin >> m;
    
    vector<ll> c(5, 0), nc(5, 0);
    for (ll i = 0; i < m; i++) {
        string s;
        int a;
        cin >> s >> a; a--;
        if (champ[s]) {
            c[a]++;
        } else {
            nc[a]++;
        }
    }

    dbg(c, nc);

    ll l = 0, r = m;

    auto cond = [&] (ll mid) {
        ll count_champ = 0;
        for (ll i = 0; i < 5; i++) {
            ll champ_choose = 0, non_champ_choose = 0; 
            if (c[i] + nc[i] < mid) {
                return false;
            }
            champ_choose = min(c[i], mid);
            non_champ_choose = max(0ll, mid - champ_choose);

            count_champ += champ_choose;
        }
        if (count_champ >= mid) {
            return true;
        }
        return false;
    };

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (cond(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return r;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
