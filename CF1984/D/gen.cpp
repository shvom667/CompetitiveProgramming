#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

int main(int argc, char** argv) {
	mt19937 rng(atoi(argv[1]));
	auto rnd = [&] (ll a, ll b) {
		return a + rng() % (b - a + 1);
	};
  ll n = rnd(4, 4);
  string s = "";
  ll cnt = rnd(0, n - 1);
  for (ll j = 0; j < n; j++) {
    ll i = rnd(0, 25);
    ll k = rnd(0, 1);
    if (k) {
      s += 'a';
    } else {
      s += 'b';
    }
  }
  cout << s << '\n';
  return 0;
}
