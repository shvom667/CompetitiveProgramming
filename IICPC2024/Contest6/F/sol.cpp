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
    Vec<ll> a(n);
    map<ll, ll> freq;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    ll fans = 0;
    vector<ll> xtra;
    for (auto&[u, v]: freq) {
        fans += max(0ll, v -2);
        if (v >= 3) xtra.pb(u);
    }
    vector<pair<ll, ll>> vp;
    for (auto& u : xtra) {
        freq[u] = 2;
    }
    for (auto& [u, v] : freq){

        vp.pb({u, v});
    } 

    sort(begin(vp), end(vp), [&] (auto x, auto y){
        return x.first < y.first;
    });

    dbg(vp);

    dbg(freq);

    vector<pair<ll,ll>> deque1, deque2;

    for (ll i = 0; i < (ll)vp.size(); i++) {
        if (vp[i].second == 1) {
            deque2.push_back({vp[i]});
            continue;
        }
        if (deque1.size() > deque2.size()) {
            deque2.push_back({vp[i].first, 1});
            deque2.push_back({vp[i].first, 1});
        }
        else {
            deque1.push_back(vp[i]);
        }
    }

    dbg(deque1);
    dbg(deque2);

    fans += ((ll)deque1.size() + (ll)deque2.size() + 1)  / 2;
    fans += (ll)deque1.size();

    return fans;
}

auto solve2() {

    ll n;
    cin >> n;
    Vec<ll> a(n);
    map<ll, ll> freq;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    ll fans = 0;
    vector<ll> xtra;
    for (auto&[u, v]: freq) {
        fans += max(0ll, v -2);
        if (v >= 3) xtra.pb(u);
    }
    vector<pair<ll, ll>> vp;
    for (auto& u : xtra) {
        freq[u] = 2;
    }
    for (auto& [u, v] : freq){

        vp.pb({u, v});
    } 

    sort(begin(vp), end(vp), [&] (auto x, auto y){
        return x.first < y.first;
    });

    dbg(vp);

    dbg(freq);
    vector<ll> doubles, singles;
    dbg(vp);
    for (ll i = 0; i < (ll)vp.size(); i++) {
        if (vp[i].second == 2) {
            doubles.pb(vp[i].first);
        } else {
            singles.push_back(vp[i].first);
        }
    }

    reverse(begin(doubles), end(doubles));
    dbg(singles);
    dbg(doubles);

    ll l = 0, r = (ll)doubles.size();
    
    auto cond = [&] (ll mid) {

        bool ok=true;
        vector<ll> chosen, left;
        for (ll i = 0; i < mid; i++) {
            chosen.pb(doubles[i]);
        }
        
        for (ll j = mid; j < (ll)doubles.size(); j++) {
            left.pb(doubles[j]);
            left.pb(doubles[j]);
        }
        for (ll i = 0; i < (ll)singles.size(); i++) {
            left.pb(singles[i]);
        }

        sort(begin(left), end(left));
        sort(begin(chosen),end(chosen));
        
        dbg(chosen);
        dbg(left);

        for (ll i = 0; i < (ll)chosen.size(); i++) {

            if (i == (ll)chosen.size() - 1) {
                if (i >= left.size()) {
                    break;
                }
                if (left[i] > chosen[i]) {
                    ok = false;
                }
                continue;
            }
            if (i >= left.size()) {
                ok=false;
                break;
            }
            if (left[i] > chosen[i]) {
                ok = false;
                break;
            }

        }
        return ok;
    };

    // dbg(cond(2));
    // return 0ll;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        // [0..mid-1]


        if (cond(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    dbg(r);

    ll tot = ((ll)doubles.size() - r) * 2 + (ll)singles.size() + r;

    fans += (tot + 1) / 2;
    fans += r;
    return fans;
    
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve2();
        cout << res << "\n";
    }
    return 0;
}
