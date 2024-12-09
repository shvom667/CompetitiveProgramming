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

auto solve(ll n, vector<ll> a) {
    
    vector<ll>  p(n + 1);
    for (ll i = 1; i <= n; i++) 
    {
        p[a[i]] = i;
    }
    Vec<pair<ll,ll>>fans;

    auto swp = [&] (ll x, ll y) {
        fans.pb({x,y});
        p[a[x]] = y;
        p[a[y]] = x;
        swap(a[x],a[y]);
        // dbg("in", a);
    };

    for(ll v = n; v >= n / 2 + 1; v--) {
        if (p[v] >= 1 && p[v] <= n / 2) {
            auto pos = p[v];
            swp(pos, n);
            swp(1, n);
            swp(1, v);
            if (v != n && pos != 1)
                swp(pos, n);
        }
        else { //p[v] > n / 2;    
            auto pos = p[v];
            swp(1,pos);
            swp(1, v);
        }
        dbg(a);
    }

    for (ll v = n / 2; v >= 1; v--) {
        ll pos = p[v];
        swp(pos, n);
        swp(v, n);
        if (a[n] != n) {
            swp(pos, n);
        }
    }

    cout << (ll)fans.size() << "\n";
    for(auto&x:fans){
        cout<<x.first << " " << x.second << '\n';
    }

    return a;
}

auto bf() {
while (true) {
    ll n = rnd(1,10)*2;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    random_shuffle(begin(a),end(a));

    vector<ll> b(n + 1, 0), s(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        b[i] = a[i - 1];
        s[i] = i;
    }
    auto res = solve(n, b);

    bool cond = false;

    dbg(res);

    for(ll i = 1; i <= n; i++) {
        if (res[i] != i) {
            cond = true;
            dbg(i);
        }
    }

    if (!cond) {
        cout<<"Ok\n";
    }else{
        cout << n << "\n";
        for(auto&x:a){
            cout<<x<<" ";
        }   cout<<'\n';
        exit(0);
    }

}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // bf();

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n; cin >> n;vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
	    auto res = solve(n, a);
	    // cout << res << "\n";
    }
    return 0;
}
