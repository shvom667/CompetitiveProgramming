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


#define ALL(x) begin(x), end(x)
template <typename T> void makeUniq(vector<T> &vec) {
  sort(begin(vec), end(vec));
  vec.resize(unique(ALL(vec)) - vec.begin());
}

map<ll, ll> cmp, dmp;
vector<ll> tot;
void compress(Vec<ll> &tot) {
  makeUniq(tot);
  ll n = tot.size();
  for (ll i = 1; i <= n; i++) {
    cmp[tot[i-1]] = i;
    dmp[i] = tot[i-1];
  }
}

struct Point {
    ll x, y;
};

void read(Point& p) {
    cin >> p.x >> p.y;
}

const ll inf = -1e12;


struct FenwickTree {
    ll size;
    vector<ll> fen;

    FenwickTree(ll n) : size(n), fen(n + 1, 0) {}

    void update(ll i, ll delta) {
        while (i <= size) {
            fen[i] += delta;
            i += i & -i;
            dbg(i);
        }
    }

    ll sum(ll i) {
        ll res = 0;
        while (i > 0) {
            res += fen[i];
            i -= i & -i;
        }
        return res;
    }

    ll query(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
};

auto solve() {
    ll n;
    cin >> n;

    vector<Point> in(n);

    for(ll i = 0; i < n; i++) {
        read(in[i]);
        tot.pb(in[i].x);
        tot.pb(in[i].y);
    }
    tot.pb(-inf);
    tot.pb(inf);

    compress(tot);

    for(ll i = 0; i < n; i++) {
        in[i].x = cmp[in[i].x];
        in[i].y = cmp[in[i].y];
    }

    ll N = tot.size();

    vector<vector<ll>> y_for_x(N + 2), x_for_y(N + 2);

    for (ll i = 0; i < n; i++) {
        y_for_x[in[i].x].pb(in[i].y);
        x_for_y[in[i].y].pb(in[i].x);
    }

    vector<ll> pre(N + 2, 0), suf(N + 2, 0);

    for (ll i = 0; i < N; i++) {
        for(auto&y : y_for_x[i]) {
            pre[y]++;
        }
    }


    ll L, R;
    L = 0, R = n / 4;

    ll g_x, g_y;
    g_x = g_y = -1;

    dbg(cmp);

    auto cond = [&] (ll mid) {
        dbg(mid);
        ll suf_y = N + 1, pre_y = 0;
        
        FenwickTree suf_fen(N+2), pre_fen(N+2);

        dbg(suf);
        dbg(pre);

        for (ll i = 1; i < (ll)suf.size(); i++) {
            suf_fen.update(i, suf[i]);
        }
        for (ll i = 1; i < (ll)pre.size(); i++) {
            pre_fen.update(i, pre[i]);
        }

        dbg("hello");

        for (ll x_cor = N + 1; x_cor >= 1; x_cor--) {
            for(auto&y_cor : y_for_x[x_cor]) {
                suf_fen.update(y_cor,  1);
                pre_fen.update(y_cor, -1);
            }

            while (suf_y - 1 >= 0 && suf_fen.query(0, suf_y - 1) >= mid) { // you can go down, go down
                suf_y--;
            }
            while(pre_y < N + 1 && pre_fen.query(0, pre_y) < mid) {   // you have to go up go up
                pre_y++;
            }

            dbg("hello");

            ll y_cor = max(suf_y, pre_y);
            if (suf_fen.query(0 , y_cor) >= mid && suf_fen.query(y_cor + 1, N + 1) >= mid && 
                pre_fen.query(0, y_cor) >= mid && pre_fen.query(y_cor + 1, N + 1) >= mid) {
                
                g_x = x_cor;
                g_y = y_cor + 1;
                return true;
            }
        }


        return false;
    };

    // auto res = cond(1);
    // dbg(res);
    // return L;

    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (cond(mid)) {
            L = mid + 1;
        }   else {
            R = mid - 1;
        }
    }

    if (R == 0) {
        cout << R << '\n';
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    cout << R << '\n';
    cond(R);
    cout << dmp[g_x] << " " << dmp[g_y] << '\n';

    cmp.clear();
    dmp.clear();
    tot.clear();

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
    }
    return 0;
}
