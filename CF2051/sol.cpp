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
	ll n, m, q;
	cin >> n >> m >> q;
	vector<ll> qur(q);
	m--;
	for (ll i = 0; i < q; i++) {
		cin >> qur[i];
		qur[i]--;
	}
	vector<ll> fans;
	if (qur[0] == m) {
		fans.pb(2);
		ll f = 0, e = n -  1;
		for (ll i = 1; i < q; i++) {
			if (qur[i] > f) {
				f++;
			}
			if (qur[i] < e) {
				e--;
			}
			fans.push_back(f + 1 + n - e);
		}
	} else {
		fans.pb(2);
		ll mid_start = m, mid_end = m;
		if (qur[0] < mid_start) {
			mid_start--;
		}
		if (qur[0] > mid_end) {
			mid_end++;
		}
		bool inflection = false;
		ll very_start = -1, very_end = n + 1;
		for (ll i = 1; i < q; i++) {
			dbg(qur[i]);
			dbg(very_start, mid_start, mid_end, very_end);
			if (!inflection && (qur[i] >= mid_start && qur[i] <= mid_end)) {
				inflection = true;
				very_start = 0;
				very_end = n - 1;
				fans.pb(very_start + 1 + n - very_end + min(very_end-1, mid_end) - max(mid_start, very_start+1) + 1);

				// fans.pb(very_start + 1 + n - very_end + mid_end - mid_start + 1);
				continue;
			}
			if (inflection) {
				if (qur[i] > very_start) {
					if (very_start < mid_start - 1) {
						very_start++;
					}
				}
				if (qur[i] < very_end) {
					if (very_end > mid_end + 1) {
						very_end--;
					}
				}
				if (qur[i] < mid_start) {
					if (mid_start > very_start + 1) {
						mid_start--;
					}
				}
				if (qur[i] > mid_end) {
					if (mid_end < very_end - 1) {
						mid_end++;
					}
				}
				// [0...very_start]
				//
				// [very_end ... n  - 1]
				fans.pb(very_start + 1 + n - very_end + min(very_end-1, mid_end) - max(mid_start, very_start+1) + 1);
			}
			if (!inflection) {
				if (qur[i] < mid_start) {
					mid_start--;
				}
				if (qur[i] > mid_end) {
					mid_end++;
				}
				fans.pb(mid_end - mid_start + 1);
			}
		}
	}
	for(auto&x:fans){
		x=min(x,n);
	}
	return fans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		for (auto x : res) {
			cout << x << " ";
		}	cout << '\n';
	}
	return 0;
}

/*
18 15 4
13 15 1 16

0: 15
1: 14 15
2:1   14 15    18
3:1 13 14 15 17 18

16: 1 2  13 14 15 16 17 18

*/