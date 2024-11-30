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

// ============
const ll INF = 1e9;
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
		T ans = curr + upd;
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
  vector<ll> a(n);
  ll fans = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  vector<ll> pi(n, -1), ni(n, n);
  // map<ll, ll> mp1,mp2;
  vector<ll>mp1(n+1, -1),mp2(n+1,-1);
  for (ll i = 0; i < n; i++) {
    if(mp1[a[i]]==-1) {
      pi[i] = -1;
    } else {
      pi[i] = mp1[a[i]];
    }
    mp1[a[i]] = i;
  }
  for(ll i=n-1;i>=0;i--){
    if(mp2[a[i]]==-1){
      ni[i]=n;
    }else{
      ni[i]=mp2[a[i]];
    }
    mp2[a[i]]=i;
  }

  vector<pair<ll,pair<ll,ll>>> uq;
  for(ll i=0;i<n;i++){
    uq.push_back({pi[i]+1,{ni[i]-1,i}});
  }

  sort(begin(uq),end(uq),[&](auto x,auto y){
    return x.first>y.first;
  });
  // dbg(uq);
  // exit(0);

  Lsegtree<ll, ll> seg(n, INF, 0);
  vector<ll> dummy(n, 0);
  seg.build(dummy);

  vector<vector<pair<ll,ll>>> er(n);
  vector<ll>w(n,n);

  for(ll i=0;i<n;i++){
    while(!uq.empty() && uq.back().first <= i) {
      auto p=uq.back();
      uq.pop_back();
      seg.update(p.second.second,p.second.first, 1);
      er[p.second.second].push_back({p.second.second,p.second.first});
    }
    
    if(seg.query(i,n-1)>0){
      w[i]=n;
    }else{
      ll L=i+1,R=n-1;
      auto cond=[&](ll mid){
        return seg.query(i,mid)==0;
      };
      while(L<=R){
        ll mid=L+(R-L)/2;
        if(cond(mid)) {
          R=mid-1;
        }else{
          L=mid+1;
        }
      }
      w[i]=L;
    }

    for(auto&[x,y]:er[i]){
      seg.update(x,y,-1);
    }
  }
  
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  

  for(ll i=0;i<n;i++){
    if(w[i]<n){
      pq.push({w[i]-i+1,i});
    }
  }
  
  vector<pair<ll, ll>> found;
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    bool seen = false;
    for (auto &[u, v] : found) {
      if (t.second <= u && t.second + t.first - 1 >= v) {
        seen = true;
      }
    }
    if (!seen) {
      found.push_back({t.second, t.first + t.second - 1});
    }
  }
  dbg(found);
  ll lc = -1;
  sort(begin(found), end(found),
       [&](auto x, auto y) { return x.first < y.first; });
  for (auto &[u, v] : found) {
    if (lc >= u)
      continue;
    lc = v;
    dbg(u, v, lc);
    fans++;
  }
  return fans;
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
