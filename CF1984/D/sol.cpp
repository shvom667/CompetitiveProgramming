#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

auto solve() {
    
    string s;
    cin >> s; ll n = s.size();

  
    char ch; ll ich = -1;
    for (ll i = n - 1; i >= 0; i--) {
        if (s[i] != 'a') {
            ch = s[i];
            ich = i;
        }
    }

    if (ich == -1) {
        cout<< n - 1<<'\n';
        return;
    }

    string b = "";

    for (ll i = ich; i < n; i++) {
        b += s[i];
    }
    b += '$';
    ll sz = b.size();
    b += s;
    dbg(b);
    auto Z = z_function(b);

    dbg(Z);
    dbg(sz);
    auto same_hash = [&] (ll a, ll b) {
        assert(b< n);
        return Z[sz + a] >= b - a + 1;
    };


    vector<ll> g(n, n);

    vector<ll> ca(n, 0);
    for (ll i = 0; i < n; i++) {
        if (s[i] != 'a') {
            ca[i] = 0;
        } else {
            ca[i] = 1;
            if (i) {
                ca[i] += ca[i - 1];
            }
        }
    }
    auto all_a = [&] (ll l, ll r) {
        return ca[r] >= r - l + 1;
    };
    
    g[n - 1] = n;
    for (ll i = n - 1; i >= 0; i--) {
        if (i + 1 < n) {
            g[i] = g[i + 1];
        }
        if (s[i] == ch) {
            g[i] = i;
        }
    }
    ll fans = 0;
    for (ll len = 1; len <= n; len++) {
        bool ok = false;
        ll pmin = 1e9;
        for (ll i = 0; i < n; i+=len) {
            ll pi = i;
            i = g[i];
            if (i < n)
                pmin = min(pmin, i - pi);
            if (!all_a(pi, i - 1)) {
                break;
            }
            if (i >= n) {
                ok = true;
                break;
            }
            if (i + len - 1 >= n) {
                break;
            }
            if (!same_hash(i, i + len - 1)) {
                
                break;
            }
            if (i + len - 1 == n - 1) {
                ok = true;
                
            }
        }
        if (ok) {
            fans += pmin + 1;
        }
    }
    cout << fans <<'\n';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);        
    
    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
