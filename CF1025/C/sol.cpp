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
    string s;ll n;
    cin>>s;
    n = (ll)s.size();
    vector<ll> f(n, 0);
    f[0] =1 ;
    for (ll i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) f[i] = 1;
        else f[i] = f[i - 1] + 1;
    }
    vector<ll> ff(n, 0);
    dbg(f);
    if (s[n - 1] != s[0]) {
        ff[0] = f[n - 1] + 1;
        for(ll i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                ff[i] = 1;
            } else {
                ff[i] = ff[i - 1] + 1;
            }
        }
        return min(*max_element(begin(ff),end(ff)), n);
    }else {
        return *max_element(begin(f),end(f));
    }

    return 0ll;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
