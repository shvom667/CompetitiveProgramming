#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif


void produce(int seed) {

    mt19937 rng(seed);

    auto rnd = [&] (int x, int y) {
      return uniform_int_distribution<int>(x, y)(rng);
    };

    ll N, Q;
    N  = 50;
    Q = 50;
    ll n = rnd(2, N);
    vector<ll> a(n, 0);

    ll q = rnd(1, Q);
    vector<vector<int>> qry;

    dbg(n, q);

    for (ll i = 1; i <= q; i++) {
        ll l, r, u;
        l = rnd(1, n - 1);
        r = rnd(l + 1, n);
        u = rnd(-N, N);
        dbg(i, l, r, u);
        qry.pb({l, r, u});
    }

    cout << n << "\n";
    for (auto& x : a) {
        cout << x << " ";
    }   cout << "\n";

    cout << q << "\n";

    for (auto&x : qry) {
        cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    }
}

int main(int argc, char* argv[]) {

    produce(atoi(argv[1]));

    return 0;
}
