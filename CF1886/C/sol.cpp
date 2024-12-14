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
    string s;
    ll n, k;
    cin>>s;
    cin >> k;
    n = s.size();
    
    deque<pair<ll, ll>> dq;

    for (ll i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            dq.push_back({i, i + 1});
        }
    }
    dbg(dq);
    ll len = n;
    ll sum = 0;
    set<ll> not_rem;
    for(ll i=0;i<n;i++)not_rem.insert(i);
    set<ll> rem;
    for (ll i = 1; i <= n; i++) {
        if (dq.empty()) break;
        if (k <= len) break;
        auto t = dq.front();
        dbg(t.first);
        rem.insert(t.first);
        not_rem.erase(t.first);
        dq.pop_front();
        ll pqr = -1;
        auto it = not_rem.upper_bound(t.first);
        if (it != begin(not_rem)) {
            it--;
            pqr = *it;
        }
        if (pqr >= 0 && s[pqr] > s[t.second]) {
            dq.push_front({pqr, t.second});
        }

        k -= len;
        dbg(len);
        len--;
    }

    dbg(rem);

    dbg(dq);

    string ss = "";
    for(ll i = 0; i < n; i++) {
        if (rem.count(i) == 0) {
            ss += s[i];
        }
    }
    dbg(ss, k);
    dbg(k);

    len = (ll)ss.size();
    dbg(len);
    for (ll i = 0; i <= (ll)ss.size() + (ll)s.size(); i++) {
        if (k  <= len) break;
        ss.pop_back();
        k -= len;
        len--;
        dbg(k, len);
    }

    dbg(ss,len);
    dbg(ss, k);

    return ss[k-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res;
    }   cout<<'\n';
    return 0;
}
