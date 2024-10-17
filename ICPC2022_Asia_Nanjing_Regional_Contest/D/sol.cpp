#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#endif

auto solve(ll n, ll k, ll m, ll c, ll d, vector<ll> a)
{
    ll fans;

    ll l = 0, r = 1e18;

    auto cond = [&] (ll mid) {
        
        vector<ll> gr(n,0);
        for (ll i = 0; i < n; i++) {
            if (a[i] >= mid) {
                gr[i] = 1;
            }
            if (i) gr[i] += gr[i-1];
        }
        dbg(gr);
        vector<ll> sv(n, 0);
        if (d == 0) {
            for (ll i = 0; i < n; i++) {
                if (c + a[i] >= mid) {
                    ll s, e;
                    s = max(0ll, i - m + 1);
                    e = i;
                    sv[s] += 1;
                    if (e + 1 < n) {
                        sv[e + 1] += -1;
                    }
                }
            }
        }
        else{
            for (ll i = 0; i < n; i++) {
                ll v = (mid - c - a[i] + d  - 1) / d;
                dbg(i, v);
                if (v <= m - 1) {
                    ll lft,rht;
                    lft=max(0ll,v);
                    rht=m-1;
                    ll s, e;
                    s = max(0ll,i-rht);
                    e = i - lft;
                    if (e >= s) {
                        sv[s] += 1;
                        if (e + 1 < n) {
                            sv[e + 1] += -1;
                        }
                    }
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            if (i) sv[i] += sv[i-1];
        }
        bool ok=false;
        for (ll i = 0; i + m  - 1 < n; i++) {
            ll cur = sv[i];
            ll prv = i - 1;
            ll nxt = i + m;
            if (prv >= 0) {
                cur += gr[prv];
            }
            if (nxt < n) {
                cur += gr[n-1] - gr[i + m - 1];
            }
            if (cur >= k) {
                ok = true;
            }
        }
        dbg(sv);
        return ok;
    };
    dbg(cond(19));
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (cond(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    fans = r;
    return fans;
}

auto bf(ll n, ll k, ll m, ll c, ll d, vector<ll> a) {
    
    auto get_ans=[&](vector<ll> b){
        sort(begin(b),end(b),greater<ll>());
        return b[k-1];
    };
    ll fans=0;
    for (ll i = 0; i < n - m + 1; i++) {
        vector<ll> b = a;
        for (ll j = 0; j < m; j++) {
            b[i+j] += c + j * d;
        }
        fans=max(fans,get_ans(b));
    }
    return fans;
}

// void stress() {
// while(true){
//     ll n,  k, m, c, d;
//     n = rnd(1, 100);
//     k = rnd(1, n);
//     m = rnd(1, n);
//     c = rnd(5, 5);
//     d = rnd(5, 5);
//     vector<ll> a(n);
//     for (ll i = 0; i < n; i++) {
//         a[i] = rnd(1, 5);
//     }
//     auto sans = solve(n,k,m,c,d,a);
//     auto bans = bf(n,k,m,c,d,a);
//     if (sans == bans) {
//         cout << "OK\n";
//     } else {
//         dbg(n,k,m,c,d);
//         dbg(a);
//         dbg(bans);
//         dbg(sans);
//         cout << "NOT OK\n";
//         exit(0);
//     }
// }
// }

int main()
{
    // stress();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1;
    for (ll tc = 1; tc <= T; tc++)
    {
        ll n, k, m, c, d;
        cin >> n >> k >> m >> c >> d;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        auto res = solve(n, k, m, c, d, a);
        cout << res << "\n";
    }
    return 0;
}
