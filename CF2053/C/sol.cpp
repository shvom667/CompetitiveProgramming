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
    ll n, k;
    cin >> n >> k;
    auto f = [&] (ll n, ll k, auto & f) {
        if (n < k) #include <bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;
    auto f = [&] (ll n, ll k, auto & f) {
        if (n < k) {
            return make_pair(0ll, 0ll);
        }
        ll fans = 0;    
        ll chosen = 0;

        if (n & 1) {
            pair<ll, ll> res = f(n / 2, k, f);
            chosen = res.second;
            fans = chosen * (n + 1) - res.first + res.first;
            fans += (n + 1) / 2;
            chosen *= 2;
            chosen++;
        } else {
            pair<ll, ll> res = f(n / 2, k, f);
            chosen = res.second;
            fans = chosen * (n + 1) - res.first + res.first;
            // fans += (n + 1) / 2;
            chosen *= 2;

        }

        return make_pair(fans, chosen);
    };

    pair<ll, ll> fans = f(n, k, f);

    return fans.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}


        return make_pair(fans, chosen);
    };

    pair<ll, ll> fans = f(n, k, f);

    return fans.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
