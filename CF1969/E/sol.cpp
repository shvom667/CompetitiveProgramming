#include <bits/stdc++.h>
using namespace std;
using ll = int;
using i64=int;
#define pb push_back
template <typename T> using Vec = vector<T>;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
#define dbg(...) 42
#endif

/*
  Cool Problem
  segment tree
    -> node --  sum on range, min suffix sum on that range
    -> 
*/

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
		// T ans = (l + r);
    T ans;
    ans.first = l.first + r.first;
    ans.second = min(r.second, r.first + l.second);
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
    // dbg(tl,tr);
    assert(tl==tr);
		T ans = curr;
    ans.first += (tr-tl+1)*upd;
    ans.second += (tr-tl+1)*upd;
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
const ll INF = 1e9+10;

auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  

  ll fans = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Lsegtree<pair<ll, ll>, ll> seg(n + 1, {0,INF}, 0);
  vector<vector<ll>> I(n + 1, Vec<ll>(2, -1));
  vector<pair<ll,ll>>dummy(n+1,{0,0});
  seg.build(dummy);

  ll pp = -1;
  ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    if (I[a[i]][0] == -1) { // no previous occurance
    dbg(i,i,i);
      seg.update(i,i,1);
      I[a[i]][0] = i;
    }   
    else if (I[a[i]][0] != -1 && I[a[i]][1] == -1) { // a single previous occurance was there
      seg.update(i,i,1);
      seg.update(I[a[i]][0],I[a[i]][0], -2); 
      I[a[i]][1] = I[a[i]][0];
      I[a[i]][0] = i;
    }
    else if (I[a[i]][0] != -1 && I[a[i]][1] != -1) { // two previous occurances were there
      seg.update(i,i,1);
      seg.update(I[a[i]][0],I[a[i]][0],-2);
      seg.update(I[a[i]][1],I[a[i]][1],1);  
      I[a[i]][1] = I[a[i]][0];
      I[a[i]][0] = i;
    }
    if(seg.query(pp+1,i).second==0){
      pp=i;
      cnt++;
    }
    // for(ll j=1;j<=i;j++){
    //   cout<<seg.query(j,i).first<<"_"<<seg.query(j,i).second<<' ';
    // } cout<<'\n';
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T = 1;
  // cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
