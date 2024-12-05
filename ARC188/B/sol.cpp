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
    if (n & 1) {
        return "Yes";
    }
    if (n <= 3) {
        return "Yes";
    }
    if ((n % 2) == 0 && k == n / 2) {
        return "No";
    }
    
    if(n%4==0)return "No";
    

    return "Yes";
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
