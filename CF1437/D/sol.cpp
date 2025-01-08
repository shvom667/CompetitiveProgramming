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
    Vec<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool newLevel = true;
    vector<ll> cntNode(n + 1, 0);
    cntNode[0] = 1;
    ll curLevel = 0;
    for (ll i = 2; i <= n; i++) {
        dbg(i, a[i], cntNode, curLevel);
        if (newLevel) {
            // dbg(i);
            curLevel++;
            cntNode[curLevel - 1]--;
            cntNode[curLevel]  += 1;
            newLevel = false;
            // dbg(i, cntNode);
            // dbg(cntNode);
            continue;
        }
        if (a[i] > a[i - 1]) {
            cntNode[curLevel]++;
        } else {
            // dbg(i, curLevel, cntNode[curLevel - 1]);
            if (cntNode[curLevel - 1] == 0) {
                i--;
                newLevel = true;
                continue;
            }
            cntNode[curLevel - 1]--;
            cntNode[curLevel]++;
        }
    }

    return curLevel;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
