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
    Vec<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll q; cin >> q;

    map<pair<ll,ll>, ll> mp;

    ll fans = 0;for(auto&x:a)fans+=x;

    while (q--) {
        ll s,t,u;
        cin >> s >> t >> u;
        u--;

        if (mp.find({s,t}) != mp.end()) {
            a[mp[{s,t}]]++;
            if (a[mp[{s,t}]]>0)fans++;
            mp.erase({s,t});
        }
        if(u!=-1){
            mp[{s,t}]=u;
            a[mp[{s,t}]]--;
            if(a[mp[{s,t}]]>=0){
                fans--;
            }
        }
        

        cout << fans << '\n';
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
