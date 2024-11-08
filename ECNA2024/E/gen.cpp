#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

int main(int argc, char** argv) {
	mt19937 rng(atoi(argv[1]));
	auto rnd = [&] (ll a, ll b) {
		return a + rng() % (b - a + 1);
	};

  ll M = rnd(2, 33);
  

  ll N = rnd(1, M/2);
  ll p = rnd(0, M);

  cout << M << " " << N << " " << p << "\n";

  return 0;
}
