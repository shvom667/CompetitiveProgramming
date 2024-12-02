#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
  return 0;
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
Hard
[i][K] -> K is total number of good substrings
[i-1][Kd] -> (K - Kd) good substrings ending at index i

[i][c][K] -> index i, char c, total good substring K

[n][c][Kd]
K<=Kd<=max
'A'<=c<='B'

000
001
010
011
100
101
110
111

These are various type of substrings
We have to figure out their solutions

Looked at the editorial looser
*/
