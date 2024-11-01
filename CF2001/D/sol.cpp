#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i64 = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

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
struct Lsegtree { // add on a range & sum on a range
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
		T ans = curr;
		ans += (tr - tl + 1) * upd;
		return ans;
	}
	U combineUpdate(U old_upd, U new_upd, ll tl, ll tr) {
		U ans = old_upd;
		ans += new_upd;
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

auto solve() {
	ll n;
	cin >> n;
	vector<ll> a(n + 1, 0), d(n + 1, 0), lp(n + 1, -1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++) {
		lp[a[i]] = i;
	}
	set<ll> uq;
	for (ll i = n; i >= 1; i--) {
		uq.insert(a[i]);
		d[i] = uq.size();
	}
	Lsegtree<ll, ll> seg(n + 2, 0, 0);
	
	auto getd = [&] (ll i) {
		return d[i] + seg.query(i, i);
	};
	auto dbgd = [&] () {
			for (ll i = 1; i <= n; i++) {
				cout << d[i] + seg.query(i, i) << " ";
			}
			cout << "\n";
	};
	multiset<ll> s;
	ll l = 0, r = 0;
	
	vector<ll> fans;
	set<ll> seen;
	
	dbg(a, d);
	ll max_uniq = d[1];
	
	for (ll reqd = max_uniq, cnt = 1; reqd >= 1; reqd--, cnt++)
	{
		dbg(fans);
		//~ dbgd();
		while (r + 1 <= n && getd(r + 1) == reqd)
		{
			r++;
			if (seen.count(a[r])) continue;
			s.insert(a[r]);
		}
		dbg(reqd, r);
			
		dbg(s);
		
		ll max_s = *s.rbegin();
		ll min_s = *s.begin();
			
		dbg(max_s, min_s, l);
		
		if (cnt & 1) {
			while (a[l + 1] != max_s) {
				l++;
				if (seen.count(a[l])) continue;
				s.erase(s.find(a[l]));
			}
			l++;
			dbg(l);
			seg.update(l, lp[max_s], -1);
			assert(a[l] == max_s);
			fans.push_back(max_s);
			seen.insert(max_s);
			s.erase(a[l]);
		} else {
			while (a[l + 1] != min_s) {
				l++;
				if (seen.count(a[l])) continue;
				s.erase(s.find(a[l]));
			}
			l++;
			dbg("min", l, lp[min_s]);
			//~ dbgd();
			seg.update(l, lp[min_s], -1);
			//~ dbgd();
			assert(a[l] == min_s);
			fans.push_back(min_s);
			seen.insert(min_s);
			s.erase(a[l]);
		}
	}
	
	return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    //~ cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << (ll) res.size() << '\n';
        for (auto&x : res) {
			cout << x << " ";
		}	cout << "\n";
    }
    return 0;
}
