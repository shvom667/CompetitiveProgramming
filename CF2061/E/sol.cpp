#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto chmin(auto& x, auto y) {
    x = min(x, y);
    return x;
}
int L2[1 << 20];

void solve(int n, int m, int k, vector<int> a, vector<int> b) {


    long long fans = accumulate(begin(a), end(a), 0LL);

    priority_queue<int> pq;

    vector<vector<int>> g(n, vector<int> (m + 1, 0));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            g[i][j] = a[i];
        }
    }
    dbg(g[0][0]);
    dbg(g[0][1]);

    vector<int> value_mask(1 << m, 0);

    value_mask[0] = (1 << 30) - 1;

    for (int mask = 1; mask < (1 << m); mask++) {

        int val = (mask & - mask);
        int l2val;
        for (int bit = 0; bit < 30; bit++) {
            if (val & (1 << bit)) {
                l2val = bit;
            }
        }

        value_mask[mask] = value_mask[mask - (mask & -mask)] & b[l2val];

    }   

    dbg(value_mask);

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            chmin(g[i][__builtin_popcount(mask)], (value_mask[mask] & a[i]));
        }
    }

    dbg(g[0][1]);
    dbg(value_mask[1]);

    for (int i = 0; i < n; i++) {

        for (int j = 1; j <= m; j++) {
            pq.push(g[i][j - 1] - g[i][j]);
        }
    }




    dbg(pq);

    for (int _ = 0; _ < k; _++) {
        if ((int)pq.size() == 0) {
            break;
        }
        fans -= pq.top();
        pq.pop();

    }
    cout << fans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int prev = 1;
    L2[1] = 0;
    int v = 1;
    while (v * 2 < (1 << 20)) {
        v *= 2;
        L2[v] = prev++;
    }

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
	    solve(n, m, k, a, b);
    }
    return 0;
}