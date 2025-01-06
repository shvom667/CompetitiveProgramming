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
    vector<ll> L(n), R(n);
    for (ll i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }
    vector<ll> def(2 * n + 1, 0);
    vector<ll> cnt(2 * n + 1, 0);
    for (ll i = 0; i < n; i++) {
        if (L[i] == R[i]) {
            if (def[L[i]] == 0)
                def[L[i]]++;
            cnt[L[i]]++;
        }
    }
    for (ll i = 1; i <= 2 * n; i++) {
        def[i] += def[i - 1];
    }

    for (ll i = 0; i < n; i++) {
        if (def[R[i]] - def[L[i] - 1] == R[i] - L[i] + 1) {
            if (R[i] == L[i] && cnt[L[i]] == 1)
                cout<<1;
            else
                cout<<0;
        }else{
            cout<<1;
        }
    }cout<<'\n';
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
