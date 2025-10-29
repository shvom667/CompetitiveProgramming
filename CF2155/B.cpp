#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <functional>
#include <stack>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}


int ask(int u, int v) {
	assert(u != v);
	cout << u << " " << v << endl;
	int d;
	cin >> d;
	return d;
}



auto solve() {
	ll n;
	cin >> n;

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	int vector_index = -1;

	int d = 0;

	while (!d) {
		vector_index = rand(0, (int)v.size() - 1);
		int u = v[vector_index];

		for (int i = 0; i < v.size(); i++) {
			if (i == vector_index) continue;
			int w = v[i];
			d = ask(u, w);
			if (d == 1) {
				break;
			}
		}
		if (d == 1) {
			break;
		}
		v.erase(v.begin() + vector_index);
	}

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
