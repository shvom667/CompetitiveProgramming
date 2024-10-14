#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

auto ask(ll i, ll j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

auto solve() {
    ll n;
    cin >> n;
    set<ll> s,r;
    for (ll i = 1; i <= n; i++) s.insert(i);
    ll res = -1;
    while (s.size() > 1) {
        auto fv = *s.begin();
        s.erase(s.begin());
        auto sv = *s.begin();
        s.erase(s.begin());
        if (ask(fv, sv) == ask(sv, fv)) {
            continue;
        } else {
            ll tv = -1;
            for (ll k = 1; k <= n; k++) {
                if (k != fv && k != sv) {
                    tv = k;
                }
            }
            if (ask(fv, tv) == ask(tv, fv)) {
                res = sv;
            } else {
                res = fv;
            }
            break;
        }
    }
    if (res != -1){
        cout << "! " << res << endl;
        return;
    }
    assert(s.size() ==1);
    cout << "! " << *s.begin() << endl;
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
