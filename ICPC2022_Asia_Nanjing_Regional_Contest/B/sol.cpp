#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

const ll INF = 1e18; 

auto solve(ll n, ll k, vector<ll> a, vector<char> s, ll q, vector<ll> p, vector<ll> v) {
    dbg(n, k, a, s, q, p, v);
    vector<ll> dpl(n + 2, INF), dpr(n + 2, INF);
    dpl[0] = 0;
    ll p1 = 0;
    multiset<ll> ms;
    ms.insert(0);
    for (ll i = 1; i <= n + 1; i++) {
        if (i == 4) {
            dbg(i, ms);
            dbg(p1, i - k);
        }
        if (p1 >= i - k) {
            dpl[i] = a[i] + dpl[p1];
        } else {
            dpl[i] = a[i] + *ms.begin();
        }
        if (i - k >= 0) {
            ms.erase(ms.find(dpl[i-k]));
        }
        ms.insert(dpl[i]);
        if (s[i] == '1') p1 = i;
    }
    dpr[n + 1] = 0;
    ll pn = n + 1;
    ms.clear();
    ms.insert(0);
    for (ll i = n ; i >= 0; i--) {
        if (i == 8) {
            dbg(ms);
        }
        assert((ll)ms.size() > 0);
        if (pn <= i + k) {
            dpr[i] = a[i] + dpr[pn];
        } else {
            dpr[i] = a[i] + *ms.begin();
        }
        if (i + k <= n + 1) {
            ms.erase(ms.find(dpr[i + k]));
        }
        ms.insert(dpr[i]);
        if (s[i] == '1') pn = i;
    }

    dbg(dpl, dpr);

    vector<ll> fans;

    for (ll cq = 0; cq < q; cq++) {
        ll ind=p[cq], val=v[cq];
        if (s[ind] == '1') {
            ll res = 0;
            res += val;
            ll ml = INF, mr = INF;
            for (ll j = ind - 1; j >= max(0LL , ind - k); j--) {
                ml = min(ml, dpl[j]);
                if (s[j] == '1') break;
            }
            for (ll j = ind + 1; j <= min(n + 1, ind + k); j++) {
                mr = min(mr, dpr[j]);
                if (s[j] == '1') break;
            }
            res += ml + mr;
            fans.pb(res);
        } else {
            ll res = 0;
            res += val;
            ll ml = INF, mr = INF;
            for (ll j = ind - 1; j >= max(0LL , ind - k); j--) {
                ml = min(ml, dpl[j]);
                if (s[j] == '1') break;
            }
            for (ll j = ind + 1; j <= min(n + 1, ind + k); j++) {
                mr = min(mr, dpr[j]);
                if (s[j] == '1') break;
            }
            dbg(ml, mr);
            res += ml + mr;

            ll ans = INF;
            ll rp = ind + 1;
            ll rv = INF;
            ll erp = max(0LL, ind - k + 1) + k;
            dbg(erp);
            for (ll i = ind + 1; i <= erp; i++) {
                if (rp <= n + 1){
                    rv = min(rv, dpr[i]);
                    
                    if (s[i] == '1') rp = n + 2;
                    // rp++; 
                }
            }   
            rp = max(erp, rp);
            dbg(rp, rv);
            if (s[ind] != '1') {
                for (ll j = max(0LL, ind - k + 1); j <= ind - 1; j++) {
                    ll cur = 0;
                    cur += dpl[j];
                    if (rp <= n + 1) {
                        rv = min(rv, dpr[rp]);
                        if (s[rp] == '1') rp = n + 2;
                        rp++;
                    }
                    cur += rv;
                    dbg(j, cur);
                    if (s[j] == '1') {
                        ans = cur;
                    }
                    if (j == 5) {
                        dbg(j, cur, dpl[j], rv);
                    }
                    ans = min(ans, cur);
                }
            }
            dbg(ans, res);
            ll gans = min(ans, res);

            fans.pb(gans);
        }
    }

    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n + 2, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<char> s(n + 2, '1');
        for (ll i = 1; i <= n; i++) {
            cin >> s[i];
        }
        ll q;
        cin >> q;
        vector<ll> p(q), v(q);
        for (ll i = 0; i < q; i++) {
            cin >> p[i] >> v[i];
        }
        auto res = solve(n, k, a, s, q, p, v);
        // cout << res << "\n";

        for (auto& x : res) {
            cout << x << "\n";
        }
           // cout << "\n";
    }
    return 0;
}
