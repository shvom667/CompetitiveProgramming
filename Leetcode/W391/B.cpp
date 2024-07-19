#include <bits/stdc++.h>
using ll = int;
using namespace std;
const ll INF=1e9;
int p, q;
#define pb push_back
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
#define hell dbg("hell");
// =================
class Solution {
  public:
    int md(ll x, ll y, ll a, ll b) {
      return abs(x - a) + abs(y - b);
    }
    int chan(vector<vector<int>> points) {
      //dbg("chan : ", points);
      ll fans = 0;
      ll max1=-INF, min1=+INF, max0=-INF, min0=+INF;
      vector<int> a_max1, a_min1, a_max0, a_min0;
      ll itr_max1, itr_min1, itr_max0, itr_min0;
      for (ll i = 0; i < (ll)points.size(); i++) {
        auto v = points[i];
        ll x = v[0], y = v[1];
        if (x + y > max1) {
          max1 = x + y;
          a_max1 = {x,y};
          itr_max1 = i;
        }
        if (x + y < min1) {
          min1 = x + y;
          a_min1 = {x,y};
          itr_min1 = i;
        }
        if (x - y > max0) {
          max0 = x - y;
          a_max0 = {x,y};
          itr_max0 = i;
        }
        if (x - y < min0) {
          min0 = x - y;
          a_min0 = {x,y};
          itr_min0 = i;
        }
      }
      //dbg(a_max0, a_max1, a_min0, a_min1);
      vector<vector<ll>> worst;
      worst.pb(a_min0);
      worst.pb(a_max0);
      worst.pb(a_min1);
      worst.pb(a_max1);
      //dbg(worst);
      ll best_itr1, best_itr2;
      for (ll i = 0; i < (ll)points.size(); i++) {
        auto v = points[i];
        ll x = v[0], y = v[1];
        for (ll j = 0; j < worst.size(); j++) {
          auto v2 = worst[j];
          ll a = v2[0], b = v2[1];
          fans = max(fans, md(x,y,a,b));
          if (md(x,y,a,b) == fans) {
            best_itr1 = i;
            if (j == 0) 
              best_itr2 = itr_min0;
            if (j == 1) 
              best_itr2 = itr_max0;
            if (j == 2) 
              best_itr2 = itr_min1;
            if (j == 3) 
              best_itr2 = itr_max1;
          }
        }
      }
      p = best_itr1;
      q = best_itr2;
      return fans;
    }
    int minimumDistance(vector<vector<int>>& points) {
      ll b1, b2;
      ll res = chan(points);
      b1 = p, b2 = q;
      vector<vector<int>> p1, p2;
      for (ll i = 0; i < (ll)points.size(); i++) {
        if (i != b1) {
          p1.pb(points[i]);
        }
      }
      //dbg(res);
      //dbg(points);
      //dbg(p, q);
      //dbg(p1);
      //dbg(p2);
      for (ll i = 0; i < (ll)points.size(); i++) {
        if (i != b2) {
          p2.pb(points[i]);
        }
      }
      ll res1 = chan(p1), res2 = chan(p2);

      return min(res1, res2);
    }
};

int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> points;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    points.pb({x,y});
  }
  //dbg(points);
  Solution a;
  cout << a.minimumDistance(points) << "\n";
}
