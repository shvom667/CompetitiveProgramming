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
 

int main(int argc, char ** argv) {


    mt19937 rng(atoi(argv[1]));

    auto rand = [&] (int x, int y) {
        return uniform_int_distribution<int>(x, y)(rng);
    };

    

    ll N, M, K;
    N = 100;
    M = 100;
    K = 100;
    ll n, m, k;
    n = rand(2, N);
    m = rand(2, M);

    k = rand(1, K);
    set<vector<ll>> s;
    for (ll j = 1; j <= k; j++) {
        int x, y, nx, ny;
        x = rand(1, n-1);
        y = rand(1, m-1);
        int nxt = rand(0, 1);
        if (nxt == 0) {
            nx = x + 1;
            ny = y + 1;
        }
        if (nxt == 1) {
            nx = x + 1;
            ny = y - 1;
        }
        if (x >= 1 && x <= n && nx >= 1 && nx <= n && ny >= 1 && ny <= m && y >= 1 && y <= m) {
            vector<ll> cur;
            cur.pb(x);
            cur.pb(y);
            cur.pb(nx);
            cur.pb(ny);
            s.insert(cur);
        }
    }


    ll len = s.size();
    cout << n <<  " " << m << " " << len << "\n";

    for (auto&v : s) {
        cout << v[0] << " "  << v[1] << " " <<  v[2] << " " << v[3] << "\n";
    }

    return 0;
}
