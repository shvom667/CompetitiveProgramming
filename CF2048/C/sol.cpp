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
    string s;ll n;
    cin >> s; n = (ll)s.size();

    ll fp0 = -1;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            fp0 = i;
            break;
        }
    }
    if (fp0 == -1) {
        cout << 1 <<  " " << n << " " << 1 << " " << 1 << '\n';
        return;
    }

    string best = s;
    dbg(s);
    dbg(best);
    ll sv = 0;
    best[n - 1] = ((best[n - 1] - '0') ^ 1) + '0';
    for (ll i = 0; i < fp0; i++) {
        string cur = s;
        ll len = n - fp0;
        if (s[i] == '1') {
            ll itr = fp0;
            for (ll  j = i; j <= i + len - 1; j++) {
                if (s[j] == '1') {
                    if (cur[itr] == '1') cur[itr] = '0';
                    else cur[itr] = '1';
                    itr++;
                } else {
                    itr++;
                    // cur[j] = s[j];
                }
            }
        }
        dbg(cur, best);
        if (cur > best) {
            best = cur;
            sv = i;
        }

    }
    ll len = n - fp0;
    cout << 1 << " " << n << " " << sv + 1 << " "  << sv + len << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
	    // auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
