#include<bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using i64 = long long;

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n((int)(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace atcoder;

constexpr int B = 5;
int mod[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
int base[B];
struct Hash {
  long long h1, h2, pw;
};
using T = array<Hash, B>;

T op(T lhs, T rhs) {
  T res;
  for (int i = 0; i < B; i++) {
    res[i].h1 = (lhs[i].h1 * rhs[i].pw + rhs[i].h1) % mod[i];
    res[i].h2 = (lhs[i].h2 + lhs[i].pw * rhs[i].h2) % mod[i];
    res[i].pw = lhs[i].pw * rhs[i].pw % mod[i];
  }
  return res;
}
T e() {
  T res;
  for (int i = 0; i < B; i++) res[i] = {0, 0, 1};
  return res;
}
using SegTree = atcoder::segtree<T, op, e>;

T gen(char c) {
  T res;
  for (int i = 0; i < B; i++) res[i].h1 = res[i].h2 = c, res[i].pw = base[i];
  return res;
}



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
		T ans;
    ans.first = min(l.first, r.first);
    ans.second = max(l.second, r.second);
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

using pl = pair<ll, ll>;
const ll INF64 = 1e17;
pl id = {INF64, -INF64};

void solve() {
  mt19937_64 rng(time(0));
  for (int i = 0; i < B; i++) base[i] = rng() % mod[i];

  cin.tie(0)->sync_with_stdio(0);
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  Lsegtree<pl, ll> all_eq(N+1, id, -INF64);

  ll dp[N];
  for (ll i = 0; i < N; i++) dp[i] = i;

  for (ll i = 0; i < N; i++) {
    if (i + 2 < N) {
      if (S[i] == S[i+2]) {
        dp[i] = dp[i+2];
      }
    }
  }

  for (ll i = 0; i < N; i++) {
    all_eq.update(i, i, (ll)S[i]);
  }

  vector<T> init(N);
  for (int i = 0; i < N; i++) init[i] = gen(S[i]);
  SegTree seg{init};

  while (Q--) {
    bool cp, aeq, alt;
    cp = aeq = alt = false;
    int l, r;
    cin >> l >> r;
    --l;
    if (l == r) {
      cout << 0 << "\n";
      continue;
    }
    // cout << l << " " << l + 1 << " "  << N << "\n";
    assert(l+1<N);
    if (min(dp[l], dp[l+1]) >= r-1) {
      alt = true;
    }

    auto h = seg.prod(l, r);
    bool flag = true;
    for (int i = 0; i < B; i++) flag &= h[i].h1 == h[i].h2;
    if (flag) {
      cp = true;
    }
    pl eee = all_eq.query(l,r-1);
    ///cout << l << " " << r-1 << "\n";
    //cout << "eee : " << eee.first << " " << eee.second << "\n";
    if (eee.first == eee.second) {
      aeq = true;
    }
    //cout<<cp<< " " << aeq << " " << alt << "\n";
    if (aeq) {
      cout << 0 << "\n";
      continue;
    }
    if (alt) {
      ll nd = (r-l)/2;
      ll sum = nd*(nd+1);
      //cout << nd  << l << " " << r << "\n";
      if((r-l)%2==0 && cp) {
        sum -= (r-l);
      }
      cout << sum << "\n";
      continue;
    }
    ll n = (r - l);
    ll fans = (n*(n+1))/2;
    fans -= 1;
    if (cp) {
      fans -= n;
    }
    cout << fans << "\n";
  }
}

signed main() {
  ll t;
  cin >> t;
  while(t--) solve();
  return 0;
}

