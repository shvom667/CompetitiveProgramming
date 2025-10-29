#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
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

auto solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}


	function <vector<ll>(vector<ll>)> S = [&] (vector<ll> a) {

		vector<ll> f(n + 1, 0);

		ll mex = 0;
		for (ll i = 0; i < n; i++) {
			f[a[i]]++;
		}


		for (ll i = 0; i < n; i++) {
			if (f[i] > 0) {
				mex++;
			} else {
				break;
			}
		}
		
		vector<ll> b = a;

		for (ll i = 0; i < n; i++) {
			if (a[i] >= mex)	 {
				b[i] = mex;
			} else {
				if (f[a[i]] > 1) {
					b[i] = mex;
				} else {
					assert(f[a[i]] == 1);
					b[i] = a[i];
				}
			}
		}
		
		return b;
	};

	if (k) {
		k--;
		a = S(a);
	}
	if (k) {
		k--;
		a = S(a);
	}
	if (k) {
		k--;
		a = S(a);
	}
	if (k) {
		k--;
		a = S(a);
	}

	ll fans=0;
	if (k == 0) {
		for(auto x : a) {
			fans+=x;
		}
		return fans;
	}

	if (k&1) {
		a = S(a);
	} else {

	}

		for(auto x : a) {
			fans+=x;
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
		cout << res << "\n";
	}
	return 0;
}

/*
if something is single it always remains

0 1 2 3 x [] x+2 x+3

next step => 


only have values till x+1

some present multiple times, some present single time, 0 present single time

next step
1. 0 always zero
2. something is single it remains that
3. something present multiple time it becomes x + 2


all value present multiple times become x + 2
the smallest value present multiple times does not exist now

0 1 2 3 .. y-1 [y] y + 1 ...

next step

0 1 2 3 y - 1 y y yy y

this is the final state

all the y's can go to y + 1 and come back to y so this is a switch 

at max 4 moves

next step


0 1 2 3 x x+1


*/