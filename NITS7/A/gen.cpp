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


    ll n, m, r1, r2;
    n = rnd(1, 15);
    m = rnd(1, 15);
    r1 = rnd(1, 15);
    r2 = rnd(1, 15);
    cout << n << " " << m << " " << r1 << " " << r2 << "\n";
  return 0;
}
