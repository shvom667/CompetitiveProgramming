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
const ll INF = 1e18;
auto solve() {
    ll n, k;
    cin >> n >> k;

    ll tot = 0;

    vector<ll> a(n);
    
    sort(begin(a), end(a));

    deque<pair<ll, ll>> c(k);

    for (ll i = 0; i < k; i++) {
        cin >> c[i].first >> c[i].second;
    }

    sort(begin(c), end(c));

    pair<ll, ll> base = {-1, 0};   

    deque<pair<ll, ll>> dq;

    dbg(a);
    dbg(c);

    vector<ll> fans;
    for (ll i = 0; i < n; i++) {
        // if (i == 2) 
        // {
        //     dbg(i, c);
        //     dbg(c[i].first, a[i]);
        // }
        while (!c.empty() && c[0].first <= a[i]) {
            auto p = c.front();
            c.pop_front();
            dq.push_back(p);
            if (p.second == 0) {
                dq.clear();
                base = {p.first, 0};
            }
        }

        // if (i == 2) 
        // {
        //     dbg(c);
        // }

        while (base.second == 0) {
            base.first++;
            base.second = INF;
            if (!dq.empty() && dq.front().first == base.first) {
                base.second = dq.front().second;
                dq.pop_front();
            }
        }

        // dbg(c);
        dbg(i, a[i], base);
        base.second--;
        fans.pb(base.first);
    }

    ll sum = 0;
    for (auto&x: fans) {
        sum += x;
    }



    dbg(fans);
    
    string sa = "Pico", sb = "FuuFuu";

    if ( (tot - sum) & 1) {
        return sa;
    } else {
        return sb;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
