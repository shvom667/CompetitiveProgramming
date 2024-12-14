#include <bits/stdc++.h>
using namespace std;
using ll = int;
using i64 = int;
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

// ============

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return max(a, b);
    return __gcd(a, b);
}

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
		T ans = gcd(l, r);
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
		// T ans = (tr - tl + 1) * upd;
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


auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    Lsegtree<ll, ll> seg(n, 0, 0);

    seg.build(a);

    ll q;
    cin >> q;

    vector<string> fans;

    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            if (r - l + 1 == 1) {
                fans.pb("YES");
                continue;
            } 
            if (seg.query(l, r) % x == 0) {
                fans.pb("YES");
                continue;
            }   
            auto cond = [&] (ll mid) {
                return seg.query(l, mid) % x == 0;
            };

            ll L = l, R = r;
            while (L <= R) {
                ll mid = L + (R - L) / 2;
                if (cond(mid)) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            if (R + 2 > r) {
                fans.pb("YES");
                continue;
            }
            if (seg.query(R + 2, r) % x == 0) {
                fans.pb("YES");
            } else {
                fans.pb("NO");
            }
            
        }
        else {
            ll i, y;
            cin >> i >> y;
            i--;
            seg.update(i, i, y);
        }
    }

    for (auto& x : fans) {
        cout << x << '\n';
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
