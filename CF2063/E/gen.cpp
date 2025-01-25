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


		int n = rnd(3, 20);

		vector<int> parent(n + 1, -1);

		for (int i = 2; i <= n; i++) {
			parent[i] = rnd(1, i - 1);
		}
		cout << 1 << '\n';
		cout << n << '\n';

		for (int i = 2; i <= n; i++) {
			cout << i << " " << parent[i] << "\n";
		}



    return 0;
}
