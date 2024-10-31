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
const ll M = 998244353;
const ll N = 1005;
ll C[N];

auto solve() { return 0; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  C[0] = 1;
  C[1] = 1;

  for (ll i = 2; i < N; i++) {
    for (ll j = 0; j < i; j++) {
      C[i] += C[j] * C[i - j - 1];
      C[i] %= M;
    }
  }

  ll fans = 1;

  if (true) {
    fans *= C[198 / 2];
    fans %= M;
    fans *= C[100 / 2];
    fans %= M;
    fans *= C[100 / 2];
    fans %= M;
    fans *= C[402 / 2];
    fans %= M;
    fans *= C[100 / 2];
    fans %= M;
    fans *= C[100 / 2];
    fans %= M;
  }

  

  cout << fans << "\n";
  return 0;
}
