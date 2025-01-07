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
    string a,b;
    cin >> a >> b;
    ll n = (ll) a.size();
    sort(begin(a), end(a));
    sort(begin(b), end(b), greater<char> ());

    ll ia = 0, ria = (n + 1) / 2 - 1, ib = 0, rib = n / 2 - 1;
    dbg(ria, rib);
    vector<char> res(n, '-');

    ll fitr = 0;
    ll bitr = n - 1;
    bool fromStart = true;
    ll turn = 0;
    ll cntT = 0;
    while (cntT < n) {
        if (fromStart && a[ia] >= b[ib]) {
            fromStart = false;
            continue;
        }
        if (fromStart) {
            if (turn == 0) {
                res[fitr++] = a[ia++];
                turn ^= 1;
                cntT++;
                continue;
            } else if (turn == 1) {
                res[fitr++] = b[ib++];
                turn ^= 1;
                cntT++;
                continue;
            }
        } else {
            if (turn == 0) {
                res[bitr--] = a[ria--];
                turn ^= 1;
                cntT++;
                continue;
            } else if (turn == 1) {
                res[bitr--] = b[rib--];
                turn ^= 1;
                cntT++;
                continue;
            }
            dbg(res);
        }

    }

    for  (auto x : res) {
        cout<<x;
    } cout << '\n' ;
    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
