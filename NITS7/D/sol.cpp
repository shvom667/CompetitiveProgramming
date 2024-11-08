#include<bits/stdc++.h>
// ============

using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
#define ALL(x) x.begin(), x.end()

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
#define i64 long long


template<class T, class U>
// T -> node, U->update.
struct Lsegtree { // set on a range, get value of point
	vector<T>st;
	vector<U>lazy;
	ll n;
	T identity_element;
	U identity_update;
	Lsegtree(ll n, T identity_element, U identity_update) {
		this->n = n;
		this->identity_element = identity_element;
		this->identity_update = identity_update;
		st.assign(4 * n, identity_element);
		lazy.assign(4 * n, identity_update);
	}
	T combine(T l, T r) {
		// change this function as required.
		T ans = max(l, r);
		return ans;
	}
	void buildUtil(ll v, ll tl, ll tr, vector<T>&a) {
		if (tl == tr) {
			st[v] = a[tl];
			return;
		}
		ll tm = (tl + tr) >> 1;
		buildUtil(2 * v + 1, tl, tm, a);
		buildUtil(2 * v + 2, tm + 1, tr, a);
		st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
	}
	// change the following 2 functions, and you're more or less done.
	T apply(T curr, U upd, ll tl, ll tr) {
		T ans = upd;
		return ans;
	}
	U combineUpdate(U old_upd, U new_upd, ll tl, ll tr) {
		U ans = old_upd;
		ans = new_upd;
		return ans;
	}
	void push_down(ll v, ll tl, ll tr) {
		if (lazy[v] == identity_update)return;
		st[v] = apply(st[v], lazy[v], tl, tr);
		if (2 * v + 2 < 4 * n) {
			ll tm = (tl + tr) >> 1;
			lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
			lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
		}
		lazy[v] = identity_update;
	}
	T queryUtil(ll v, ll tl, ll tr, ll l, ll r) {
		push_down(v, tl, tr);
		if (l > r)return identity_element;
		if (tr < l or tl > r) {
			return identity_element;
		}
		if (l <= tl and r >= tr) {
			return st[v];
		}
		ll tm = (tl + tr) >> 1;
		return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
	}

	void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd) {
		push_down(v, tl, tr);
		if (tr < l or tl > r)return;
		if (tl >= l and tr <= r) {
			lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
			push_down(v, tl, tr);
		} else {
			ll tm = (tl + tr) >> 1;
			updateUtil(2 * v + 1, tl, tm, l, r, upd);
			updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
			st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
		}
	}



	void build(vector<T>a) {
		assert((i64)a.size() == n);
		buildUtil(0, 0, n - 1, a);
	}
	T query(ll l, ll r) {
		return queryUtil(0, 0, n - 1, l, r);
	}
	void update(ll l, ll r, U upd) {
		updateUtil(0, 0, n - 1, l, r, upd);
	}
};

 
struct plat {
    ll x, y, len;
    ll x1, x2;
    ll id;
};

template <typename T>
void makeUniq(vector<T>& vec) {
    sort(begin(vec),end(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
}
map<ll,ll> cmp,dmp;
void compress(Vec<ll>& tot) {
  makeUniq(tot);
  ll n=tot.size();
  for(ll i=0;i<n;i++){
    cmp[tot[i]] = i;
    dmp[i] = tot[i];
  }
}

plat read() {
    plat p;
    cin >> p.y >> p.x >> p.len; 
    return p;
}

void print(plat p) {
    cout << p.id << "\n";
}

plat gnd;

const ll INF = 1e9 + 30;

auto chmin(auto&x, auto y) {
    x = min(x, y);
}

auto solve() {
    ll n;
    cin >> n;
    vector<ll> tot;

    vector<plat> in;

    gnd.id = 0;
    gnd.x = 0, gnd.x1 = 0, gnd.x2 = 1e9  + 10, gnd.y = 0;
    tot.push_back(gnd.x1);
    tot.push_back(gnd.x2);

    in.push_back(gnd);

    for (ll i = 1; i <= n; i++) {
        plat p = read();
        p.id = i;
        p.x1 = p.x;
        p.x2 = p.x + p.len;
        in.push_back(p);
        tot.push_back(p.x1);
        tot.push_back(p.x2);
    }

    compress(tot);

    for (ll i = 0; i <= n; i++) {
        in[i].x1 = cmp[in[i].x1];
        in[i].x2 = cmp[in[i].x2];
    }
    sort(begin(in), end(in), [&] (auto a, auto b) {
        return a.y < b.y;
    });


    dbg("hello");

    // for (auto&p : in) {
    //     print(p);
    // }

    vector<ll> dp(n + 1, INF);

    dp[0] = 0;


    dbg("hello");
    ll sz = tot.size() + 1;
    dbg(sz);
    dbg("hello");
    Lsegtree<ll, ll> H(sz, 0ll, -INF), ID(sz, 0ll, -INF);

    vector<ll> dummy1(sz), dummy2(sz);

    for (ll i = 0; i < sz; i++) {
        dummy1[i] = 0;
        dummy2[i] = 0;
    }
    H.build(dummy1); ID.build(dummy2);

    dbg("hello");
    dbg(tot);
    dbg(cmp);
    dbg(dmp);

    for (ll i = 1; i < in.size(); i++) {

        ll below_id1 = ID.query(in[i].x1, in[i].x1);
        ll below_height1 = H.query(in[i].x1, in[i].x1); 

        ll below_id2 = ID.query(in[i].x2, in[i].x2);
        ll below_height2 = H.query(in[i].x2, in[i].x2); 

        dbg(in[i].id, below_id1, below_id2);

        chmin(dp[in[i].id], max(dp[below_id1], in[i].y - below_height1));
        chmin(dp[in[i].id], max(dp[below_id2], in[i].y - below_height2));

        H.update(in[i].x1, in[i].x2, in[i].y);
        ID.update(in[i].x1, in[i].x2, in[i].id);
    }

    for (ll i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }   cout << '\n';

    cmp.clear();
    dmp.clear();

    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    // cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
    }
    return 0;
}
