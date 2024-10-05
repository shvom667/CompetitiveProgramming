#define ONLINE_JUDGE
#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
using i64 = int;

// #define LOCAL

#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif


#ifdef LOCAL
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
  
#else
    #define rnd(...) 42
    // do other stuff
#endif
const ll INF = 1e9;
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


auto solve2(ll n, Vec<ll> a) {

    vector<ll> p(n), s(n), g(n, 1), b;
    b = a;
    reverse(begin(b),end(b));
    for (ll i = 0; i < n; i++) {
        p[i] = a[i] + i;
        s[i] = a[i] - i;
    }    
    dbg(s);
    dbg(p);
    for (ll i = 0; i < n; i++) if (i) p[i] = min(p[i], p[i-1]);
    for (ll i = n - 2; i >= 0; i--) s[i] = min(s[i], s[i+1]);
    for (ll i = 0; i < n; i++) {
        if (s[i] >= -i + 1 && p[i] >= i + 1) {

        } else {
            g[i] = 0;
        }
    }
    
    auto s1 = [&] (Vec<ll> a) {
        Vec<ll> bad(n, 0);
        dbg(a);
        Lsegtree<ll, ll> seg(n + 1, -INF, -INF);
        for (ll i = n - 1; i >= 0; i--) {
            ll q = seg.query(0, a[i]);
            if (q > a[i] + i) {
                dbg(i, q);
                bad[i] += 1;
                if (q  < n)
                    bad[q] += -1;
            }
            ll r = seg.query(a[i], a[i]);
            r = max(r, i + 1);
            seg.update(a[i], a[i], r);
        }
        for (ll i = 1; i < n; i++) bad[i] += bad[i-1];
        dbg(bad);
        return bad;
    };
    Vec<ll> r1, r2;
    if (true) {
        r1 = s1(a);
    }
    if (true) {
        r2 = s1(b);
        dbg(r2);
        for (ll i = 0; i < n/2; i++) {
            swap(r2[i], r2[n-1-i]);
        }

    }
    vector<ll> fans;
    dbg(g,r1,r2);
    for (ll i = 0; i < n;i++) {
        if (!r1[i] && !r2[i] && g[i]) {
            fans.pb(i);
        }
    }
    return fans;
}


auto solve(ll n, Vec<ll> a) {
    vector<ll> b = a;
    reverse(begin(b),end(b));
    auto good = [&] (ll x, vector<ll> a) {
        bool ok = true;
        
        for (ll i = x; i >= 0; i--) {
            if (a[i] < x - i + 1) {
                ok = false;
            }
        }
        for (ll i = x; i < n; i++) {
            if (a[i] < i - x + 1) {
                ok = false;
            }
        }
        // vector<ll> R(n + 1), L(n + 1);


        ll L[n+1], R[n+1];
        for (ll i = 0; i <= n; i++) {
            R[i] = 0;
            L[i] = 5 * n;
        }
        for (ll i = x; i < n; i++) {
            R[a[i]] = max(R[a[i]], i + 1);
        }
        for (ll i = 0; i <= n; i++) {
            if (i)
            R[i] = max(R[i], R[i-1]);
        }

        for (ll i = 0; i <= x; i++) {
            L[a[i]] = min(L[a[i]], a[i] + i);
        }
        // dbg(a);
        // dbg(L);
        // dbg(R);
        for (ll i = 1; i <= n; i++)  {
            if (L[i] >= R[i]) {
                
            } else {
                ok = false;
            }
        }
        // dbg(ok);
        return ok;
    };


    ll l = 0, r = n - 1;


    vector<ll> fans;
    for (ll i = 0; i < n; i++) {
        // if (i != 3) continue;
        if (good(i, a) && good(n-1-i, b)) {
            fans.pb(i);
        }
    }
    return fans;
}

auto bf(ll n, Vec<ll> a) {
    vector<ll> L, R;
    vector<ll> good;
    for (ll i = 0; i < n; i++) {
        bool ok = true;
        for (ll j = i; j >= 0; j--) {
            for (ll k = i; k < n; k++) {
                if (max(a[j], a[k]) < k - j + 1) {
                    ok = false;
                }
                if (a[j] < a[k]) {
                    if (a[j] < i - j + 1) {
                        ok = false;
                    }
                } else {
                    if (a[k] < k - i + 1) {
                        ok = false;
                    }
                }
            }
        }
        if (ok) {
            good.pb(i);
        }
    }
    dbg(good);
    return good;
}



auto stress() {
    while (true) {
        ll n = rnd(5, 60);
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = rnd(1, n);
        }

        auto s2ans = solve2(n, a);
        dbg("hello\n");
        auto sans = solve(n, a);
        bool ok = s2ans == sans;
        if (ok) {
            dbg("ok");
        } else {
            dbg(n);
            dbg(a);
            dbg(s2ans);
            dbg(sans);
            exit(0);

        }
    }
}


int main() {
    #ifdef LOCAL
        stress();
        return 0;
    #else

    #endif

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a) {
            cin >>x ;
        }
        auto res = solve2(n, a);
        cout << res.size() << "\n";
        // for (auto&x : res) {
        //     cout  << x << " ";
        // }   cout << "\n";
        // dbg(res);
    }
    return 0;
}
