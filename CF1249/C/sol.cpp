#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
	int n;
	cin >> n;

	int A[n];

	for (int i = 0; i < n; i++) {
		A[i] = (i + 1) * (i + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
	    // cout << res << "\n";
    }
    return 0;
}
