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


    ll M = 10;
    ll n;
    n = 5000;
    cout << n << '\n';

    for (ll i = 0; i < n; i++) {

      ll y, x, len;
      y = rnd(1, 10);
      x = rnd(1, 10);
      len = rnd(1, 10);

      cout << y << " " << x << " " << len << "\n";
    }


  return 0;
}
