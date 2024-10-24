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


// ============

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

// ============

// ============

template<class T, class U>
// T -> node, U->update.
struct Lsegtree {
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
		assert((ll)a.size() == n);
		buildUtil(0, 0, n - 1, a);
	}
	T query(ll l, ll r) {
		return queryUtil(0, 0, n - 1, l, r);
	}
	void update(ll l, ll r, U upd) {
		updateUtil(0, 0, n - 1, l, r, upd);
	}
};


// ============

template<class T, class U>
// T -> node, U->update.
struct Lsegtree1 {
	vector<T>st;
	vector<U>lazy;
	ll n;
	T identity_element;
	U identity_update;
	Lsegtree1(ll n, T identity_element, U identity_update) {
		this->n = n;
		this->identity_element = identity_element;
		this->identity_update = identity_update;
		st.assign(4 * n, identity_element);
		lazy.assign(4 * n, identity_update);
	}
	T combine(T l, T r) {
		// change this function as required.
		T ans = min(l, r);
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
		assert((ll)a.size() == n);
		buildUtil(0, 0, n - 1, a);
	}
	T query(ll l, ll r) {
		return queryUtil(0, 0, n - 1, l, r);
	}
	void update(ll l, ll r, U upd) {
		updateUtil(0, 0, n - 1, l, r, upd);
	}
};
const ll INF = 1e18;
const ll MOD = 998244353;
using pl = pair<ll, ll>;

auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(2 * n);

    for (ll i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    vector<ll> sp(n + 1), ep(n + 1);
    for (ll i = 0; i < 2 * n; i++) {
        ep[a[i]] = i;
    }
    for (ll i = 2 * n - 1; i >= 0; i--) {
        sp[a[i]] = i;
    }
    ll sz = 0;
    ll beg = 0, end = 0;
    vector<pl> intervals;
    for (ll i = 0; i < 2 * n; i++) {
        end = max(end, ep[a[i]]);
        if (end == i) {
            sz++;
            intervals.pb({beg,end});
            beg = i + 1;
            end = i + 1;
        }
    }

    map<ll, ll> ev, sv;
    for (ll i = 1; i <= n; i++) {
        ev[ep[i]] = i;
        sv[sp[i]] = i;
    }

    dbg(intervals);

    ll fans = 1;

    vector<pl> inv;

    for (ll i = 1; i <= n; i++) {
        inv.pb({sp[i], ep[i]});
    }

    dbg(inv);

    sort(inv.begin(), inv.end(), [&](auto x, auto y) {
        return x.second - x.first < y.second - y.first;
    });

    set<ll> s;
    for (ll i = 0; i < 2 * n; i++) {
        s.insert(i);
    }

    dbg(inv);
    
    DSU d(n + 1);

    // for (auto& [x, y] : inv) {
    //     auto it = s.upper_bound(x);
    //     vector<ll> erase;
    //     while (it != s.end()) {
    //         if (*it > y) break;
    //         d.unite(a[x], a[*it]);
    //         erase.push_back(*it);
    //         it++;
    //     }
    //     for (auto&val : erase) {
    //         s.erase(val);
    //     }
    //     s.erase(x);
    //     s.erase(y);
    // }

    // for (ll i = 1; i <= n; i++) {
    //     cout << d.get(i) << " \n"[i == n];
    // }

    Lsegtree<ll, ll> seg(2 * n, -INF, -INF);

    vector<ll> ending(2 * n, -1);

    for (ll i = 0; i < 2 * n; i++) {
        ending[i] = ep[a[i]];
    }

    dbg(ending);
    seg.build(ending);


    for (auto &[s, e] : inv) {
        ll me = seg.query(s, e);
        dbg(s, e);
        if (me > e) {
            d.unite(a[s], ev[me]);
            dbg(a[s], ev[me]);
        }
    }

    Lsegtree1<ll, ll> seg1(2 * n, INF, -INF);
    vector<ll> starting(2 * n, INF);
    for (ll i = 0; i < 2 * n; i++) {
        starting[i] = sp[a[i]];
    }
    seg1.build(starting);

    for (auto&[s, e] : inv) {
        ll ms = seg1.query(s, e);
        if (ms < s) {
            d.unite(a[s], sv[ms]);
        }
    }

    vector<ll> lvp(n + 1, 1e18), mvp(n + 1, -1);

    for (ll i = 1; i <= n; i++) {
        lvp[d.get(i)] = min(lvp[d.get(i)], sp[i]);
        mvp[d.get(i)] = max(mvp[d.get(i)], ep[i]);
    }

    for (auto& [s, e] : intervals) {
        ll cnt = 0;
        for (ll i = s; i <= e; i++) {
            if (lvp[d.get(a[i])] == s && mvp[d.get(a[i])] == e) {
                cnt++;
            }
        }
        dbg(cnt);
        fans *= cnt;
        fans %= MOD;
    }
    return make_pair(sz, fans);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}
