#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #ifndef ONLINE_JUDGE
// #include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
// #include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
// #else
// #define dbg(...) 42
// #define rnd(...) 42
// #endif


int ask(int x, int k, vector<int> s) {
	cout << "? " << x << " " << k << " ";;
	for (auto v : s) {
		cout << v << " ";
	}
	cout << endl;
	int ans;
	cin >> ans;

	return ans;
}

void give(int k, std::vector<int> s) {
	cout << "! " << k << " ";
	for (auto v : s) {
		cout << v << " ";
	}
	cout << endl;
}

auto solve() {

	int n;
	cin >> n;

	vector<int> all(n);
	for (int i = 1; i <= n; i++) {
		all[i - 1] = i;
	}
	int sn = -1;
	int md = -1;

	vector<int> dist(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int cmd = ask(i, n, all);
		dist[i] = cmd;
		if (cmd > md) {
			md = cmd;
			sn = i;
		}
	}


	vector<int> ans;


	ans.pb(sn);

	for (int i = md - 1; i  >= 1; i--) {
		for (int node = 1; node <= n; node++) {
			if (dist[node] == i) {
				if (ask(ans.back(), 2, {ans.back(), node}) == 2) {
					ans.pb(node);
					break;
				}
			}
		}
	}

	give(md, ans);


	assert((int)ans.size() == md);


	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
	}
	return 0;
}
