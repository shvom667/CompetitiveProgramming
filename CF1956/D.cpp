
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// =================

// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
	cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
	bool first = true;
	cerr << '{';
	for (const auto &i : x) {
		cerr << (first ? "" : ","), __print(i);
		first = false;
	}
	cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
	cerr << '(';
	__print(p.first);
	cerr << ',';
	__print(p.second);
	cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
	bool first = true;
	cerr << '(';
	apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
	vector<T> debugVector;
	while (!s.empty()) {
		T t = s.top();
		debugVector.push_back(t);
		s.pop();
	}
	reverse(debugVector.begin(), debugVector.end());
	__print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.front();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.top();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
	__print(H);
	if (sizeof...(T))
		cerr << ", ";
	_print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t = 1;
  while (t--) solve();
}

using pl = pair<ll, ll>;
void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  Vec<ll> mv(n, 0);
  ll best = 0;
  ll best_val = 0;
  Vec<pl> best_sb;
  Vec<ll> best_mv;
  for (ll mask = 0; mask < (1ll<<n); mask++) {
    for (ll k=0;k<n;k++) {
      if (mask&(1ll<<k)) {
        mv[k] = 0;
      } else {
        mv[k] = 1;
      }
    }
    ll cur_val = 0;
    Vec<pl> sb;
    for (ll k = 0; k < n; k++) {
      if (mv[k] == 0) {
        cur_val += a[k];
        if (!sb.empty()) {
          if(sb.back().second == -1)
            sb.back().second = k-1;
        }
      }
      if (mv[k] == 1) {
        if (sb.empty()) {
          sb.pb({k,-1});
          continue;
        }
        if (!sb.empty()) {
          if(sb.back().second!=-1) {
            sb.pb({k,-1});
          }
        }
      }
    }
    if (!sb.empty()) {
      if (sb.back().second == -1)
        sb.back().second=n-1;
    }
    for(auto& [s,e] : sb) {
      ll len = e - s + 1;
      cur_val += len*len;
    }
    if (cur_val > best_val) {
      best_val = cur_val;
      best = mask;
      best_sb = sb;
      best_mv = mv;
    }
  }
  dbg(best_val, best);
  dbg(best_sb);
  dbg(best_mv);
  Vec<ll> aa = a;
  function<Vec<pl>(ll , ll, ll)> get = [&] (ll s, ll k, ll len) {
    if (k==1) {
      Vec<pl> fans;
      if (aa[s]!=0) {
        fans.pb({s,s});
      }
      return fans;
    }
    Vec<pl> res;
    Vec<pl> sub_res = get(s, k-1,len);
    res = sub_res;
    if (a[s+k-1]!=0) {
      res.pb({s+k-1,s+k-1});
    }
    res.pb({s,s+k-1});
    for (ll i = s; i <= s + k -1; i++) {
      aa[i] = k;
    }
    Vec<pl> sub_res2 = get(s,k-1,len);
    for(auto&x:sub_res2) {
      res.pb(x);
    }
    return res;
  };
  Vec<pl> fans;
  for (auto& [u,v] : best_sb) {
    Vec<pl> res = get(u, v-u+1,v-u+1);
    res.pb({u,v});
    for(auto& x : res)
      fans.pb(x);
  }

  cout << best_val << " " << (ll)fans.size() << '\n';
  for (auto& [u,v]: fans) {
    cout << u + 1 << " " << v + 1 << '\n';
  }
}
