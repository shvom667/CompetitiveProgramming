#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
using i64 = long long;
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
// ============

template<class T, class U>
// T -> node, U->update.
struct Lsegtree0 {
	vector<T>st;
	vector<U>lazy;
	ll n;
	T identity_element;
	U identity_update;
	Lsegtree0(ll n, T identity_element, U identity_update) {
		this->n = n;
		this->identity_element = identity_element;
		this->identity_update = identity_update;
		st.assign(4 * n, identity_element);
		lazy.assign(4 * n, identity_update);
	}
	T combine(T l, T r) {
		// change this function as required.
		T ans;
        ans.first = min(l.first, r.first);
        ans.second = max(l.second,r.second);
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
		T ans;
        ans.first = upd;
        ans.second = upd;
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
		T ans = (l + r);
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
		T ans = (tr - tl + 1) * upd;
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
const ll INF = 1e9;
auto solve() {
    vector<string> fans;
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<char> s(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> s[i];
    }

    Lsegtree0<pair<ll, ll>, ll> seg_a(n + 1, {INF,-INF}, INF);
    vector<pair<ll, ll>> dummy(n + 1);
    for (ll i = 0; i <= n; i++) {
        dummy[i].first = dummy[i].second = a[i]; 
    }
    seg_a.build(dummy);

    Lsegtree1<ll, ll> seg_q(n + 1, 0, -INF);
    vector<ll> dummy1(n + 1, 0);
    seg_q.build(dummy1);

    auto dbg_seg = [&] () {
        for (ll i = 1; i <= n; i++) {
            cout << seg_q.query(i , i) << " ";
        }   cout << "\n";
    };
    // dbg_seg();

    set<ll> si, pr;

    for (ll i = 1; i <= n; i++) {
        if (s[i] == 'R')
            pr.insert(i);
    }

    si.insert(1);
    for (ll i = 2; i <= n; i++) {
        if (s[i] == 'R' && s[i - 1] == 'R') continue;
        if (s[i] == 'R' && s[i - 1] == 'L') {
            si.insert(i);
        }
    }
    dbg(si);

    for (auto& x : si) {
        auto it = si.upper_bound(x);
        ll r;
        if (it == end(si)) {
            r = n;
        } else {
            r = *it - 1;
        }
        auto p = seg_a.query(x, r);
        if (p.first == x && p.second == r) {
            seg_q.update(x, r, 1);
        }
    }
    

    auto update = [&] (ll x) {
        if (x > n) return;
        if (x <= 0) return;
        auto it = si.upper_bound(x);
        ll r;
        if (it == end(si)) {
            r = n;
        } else {
            r = *it - 1;
        }
        dbg(x, r);
        auto p = seg_a.query(x, r);
        if (p.first == x && p.second == r) {
            seg_q.update(x, r, 1);
        } else {
            dbg("inside");
            seg_q.update(x, r, 0);
        }
    };

    auto give = [&] () {
        ll res = seg_q.query(1, n);
        if (res == n) {
            return "YES";
        } else {
            return "NO";
        }
    };

    for (ll qr = 1; qr <= q; qr++) {
        
        ll ind; cin >> ind;
        if (s[ind] == 'R') {
            if (si.count(ind)) {
                si.erase(ind);
            }
            pr.erase(ind);
            ll nxtr, prvr;
            auto it = pr.upper_bound(ind);
            if (it != end(pr)) {
                nxtr = *it;
            }   else {
                nxtr = n + 1;
            }
            auto kt = si.upper_bound(ind);
            if (kt != begin(pr)) {
                kt--;
                prvr = *kt;
            } else {
                prvr = 1;
            }
            
            dbg(prvr, nxtr);
            si.insert(prvr);
            si.insert(nxtr);
            dbg(si);
            update(prvr); 
            update(nxtr);   
            
            s[ind] = 'L';
        }
        else {
            
            ll prvr = -INF;
            ll nxtr = INF;
            auto it = pr.upper_bound(ind);
            if (it != end(pr)) {
                nxtr = *it;
            }
            auto jt = si.upper_bound(ind);
            if (it != begin(pr)) {
                it--;
                prvr = *it;
            }
            if (prvr < ind - 1) {
                si.insert(ind);
            }
            if (nxtr == ind + 1) {
                si.erase(ind + 1);
            }
            // dbg(prvr, nxtr);
            ll nitr = n + 1, pitr = -1;
            // dbg(si);
            it = si.upper_bound(ind);
            jt = it;
            jt--;
            if (it != end(si)) {
                nitr = *it;
            }
            if (it != begin(si)) {
                pitr = *jt;
            }
            ll ppitr = -1;
            if (jt != begin(si)) {
                jt--;
                ppitr = *jt;
            }

            // dbg(pitr, nitr);
            update(ppitr);
            update(pitr);
            update(nitr);
            
            pr.insert(ind);
            s[ind] = 'R';
        }

        fans.push_back(give());
    }
    
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto& x: res){
            cout << x << "\n";
        }
    }
    return 0;
}
