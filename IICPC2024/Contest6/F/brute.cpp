#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
#define ONLINE_JUDGE
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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> I(n, 0);
    for (ll i = 0; i < n; i++) {
        I[i] = i;
    }
    ll fans = 0;
    do {
        vector<ll> b(n);
        for (ll i = 0; i < n; i++) {
            b[i] = a[I[i]];
        }
        dbg(b);
        
        ll cur = 0;
        for (ll i = 0; i < n; i++) {
            ll lft, rht;
            lft = rht = -1;
            if (i) lft =max(lft, b[i - 1]);
            if (i + 1 < n) rht = max(rht, b[i + 1]);
            if (b[i] >= max(lft, rht)) {
                cur++;
            }
        }
        fans = max(fans, cur);
    } while (next_permutation(begin(I), end(I)));

    cout << fans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
