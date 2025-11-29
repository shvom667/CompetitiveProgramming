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


#ifndef ONLINE_JUDGE
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/debug.cpp"
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif


auto solve() {
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
		// auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}


/*

n segments on a number line

seg_i = [l_i, r_i]



n = 2 * 10 ^ 5

li, ri 

initially all segments are unmarked

1. 	In the k-th op if there are atleast 2 unmarked segment choose any two unmarked segments 
	[li, ri] and [lj, rj]
	mark both of them, and 
	add a new marked segment [xk, yk]

	l[i] <= x[k] <= r[i]

	l[j] <= y[k] <= r[j]

	x[k] <= y[k]

2. If there is exactly 1 unmarked segment remaining, mark it

maximum possible sum of marked segment at the end

Test Case 1; 
1 1e9
1 1e9

> answer = 1e9 - 1 + 1e9 - 1 + 1e9 - 1 = 3e9 - 3


Test Case 2: 
3
1 10
2 15
3 9

op1 :

[1, 10] [2, 15] extra addn [1, 15] (all marked now)

> this_answer = 9 + 13 + 14 

last op [3, 9] = 6

> this_answer = 6

final_answer > 42

Test Case 3: 

5
1 11
2 7
15 20
1 3
11 15

ans> 59





Test Case 4

1
1e9 1e9

ans> = 0




*/