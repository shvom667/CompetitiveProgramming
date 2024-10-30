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
    vector<ll> a(n);
    ll fans = 0;
    for (ll  i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        if (a[i] == 0) {
            fans += i + 1;
        }
    }

    deque<ll> dq;

    for (ll i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            dq.push_back(i);
        }
        if (a[i] == 0) {
            if (dq.size() > 0) {
                dq.pop_front();
            }
        }
    }
    reverse(begin(dq), end(dq));

    for (ll i = 0; i < ((ll)dq.size() + 1) / 2; i++) {
        fans += dq[i] + 1;
    }

    return fans;
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
