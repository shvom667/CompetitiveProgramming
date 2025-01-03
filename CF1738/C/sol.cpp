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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll co = 0, ce = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) co++;
        else ce++;
    }
    if (co % 4 == 0) {
        return "Alice";
    }
    if (co % 4 == 2) {
        return "Bob";
    }
    if (co % 4 == 3) {
        return "Alice";
    }
    if (co % 4 == 1) {
        if (ce & 1) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
    return "";
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
/*
multiple test cases

input arr, size = n

ce = count of even no 
co = count of odd no


just even 
    alice always win

just odd
    co % 4 == 0:
        alice
    co % 4 == 1:
        bob
    co % 4 == 2:
        bob
    co % 4 == 3:
        alice

ce % 2 == 0
    normalization
        co % 4 == 0
            alice
        co % 4 == 3
            alice
    bob does normalization bob wins
        co % 4 == 1:
            bob

        co % 4 == 2:
            bob
ce % 2 == 1:
    alice makes a move
    reduced game -> 1 even all odd

        if floor(n / 2) odd:
            alice wins
        if floor(n / 2) even:
            n even:
                alice
            n odd:
                bob


*/