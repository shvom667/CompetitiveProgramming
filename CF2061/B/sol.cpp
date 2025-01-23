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

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a), greater<ll> ());

    set<ll> s;
    
    map<ll, ll> mp;

    for (ll i = 0; i < n; i++) {
        mp[a[i]]++;
        if (mp[a[i]] >= 2) {
            s.insert(a[i]);
        }
    }


    auto remove = [&] (ll x) {
        mp[x]--;
        if (mp[x] <= 1) {
            s.erase(x);
        }
    };

    auto add = [&] (ll x) {
        mp[x]++;
        if (mp[x] > 1) {
            s.insert(x);
        }
    };
    Vec<ll> fans;
    remove(a[0]);
    for (ll i = 0; i < n - 1; i++) {
        if (i - 1 >= 0) {
            add(a[i - 1]);
        }
        
        remove(a[i +1]);

        if (!s.empty() && *s.rbegin() >= (a[i] - a[i + 1]) / 2 + 1 ) {
            fans  = {*s.rbegin(), *s.rbegin(), a[i], a[i + 1]};
            return fans;
        }
    }

    for (ll i = 1; i + 2 < n; i++) {
        if (a[i] == a[i + 1]) {
            if ((a[i - 1] - a[i + 2]) / 2 + 1 <= a[i]) {
                fans = {a[i - 1], a[i], a[i + 1], a[i + 2]};
                return fans;
            }
        }
    }

    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();

        if ((ll)res.size() == 0) {
            cout << -1 << '\n';
            continue;
        }
        assert((ll)res.size() == 4);

        for (auto x : res) {
            cout << x << " ";
        }   cout << '\n';

    }
    return 0;
}
