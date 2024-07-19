#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;

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
void bfs(ll i, ll j, vector<vector<char>> &a, ll n, ll m,
         vector<vector<ll>> &montime) {
  queue<pair<ll, pair<ll, ll>>> q;
  montime[i][j] = 0;
  q.push({0, {i, j}});

  ll dr[] = {0, 1, 0, -1};
  ll dc[] = {1, 0, -1, 0};
  while (!q.empty()) {
    ll steps = q.front().first;
    ll k = q.front().second.first;
    ll l = q.front().second.second;
    q.pop();

    for (ll i = 0; i < 4; i++) {
      ll nk = k + dr[i];
      ll nl = l + dc[i];

      if (nk < 0 || nk >= n || nl < 0 || nl >= m || a[nk][nl] == '#' ||
          (montime[nk][nl] != -1)) {
        continue;
      }

      montime[nk][nl] = 1 + montime[k][l];
      q.push({steps + 1, {nk, nl}});
    }
  }
}
ll bfss(ll i, ll j, vector<vector<ll>> &montime,
        vector<vector<pair<ll, ll>>> &v, vector<vector<char>> &a,
        vector<vector<ll>> &vis, vector<ll> &destination) {
  vis[i][j] = 1;
  queue<pair<ll, pair<ll, ll>>> q;
  q.push({0, {i, j}});

  ll dr[] = {0, 1, 0, -1};
  ll dc[] = {1, 0, -1, 0};
  while (!q.empty()) {
    ll steps = q.front().first;
    ll k = q.front().second.first;
    ll l = q.front().second.second;
    if (k == 0 || k == n - 1 || l == 0 || l == m - 1) {
      destination[0] = k;
      destination[1] = l;
      return steps;
    }
    q.pop();

    for (ll i = 0; i < 4; i++) {
      ll nk = k + dr[i];
      ll nl = l + dc[i];

      if (nk < 0 || nk >= n || nl < 0 || nl >= m || a[nk][nl] == '#' ||
          vis[nk][nl] == 1 || montime[nk][nl] <= steps + 1) {
        continue;
      }
      vis[nk][nl] = 1;
      q.push({steps + 1, {nk, nl}});
      v[nk][nl] = {k, l};
    }
  }
  return -1;
}
string temp = "";
void s(ll i, ll j, ll I, ll J, vector<vector<pair<ll, ll>>> &v) {
  // cout << temp << "\n";
  if (i == I && j == J) {
    return;
  }
  if (v[i][j].first == i - 1 && v[i][j].second == j) {
    temp += 'D';
    s(i - 1, j, I, J, v);
  } else if (v[i][j].first == i + 1 && v[i][j].second == j) {
    temp += 'U';
    s(i + 1, j, I, J, v);
  } else if (v[i][j].first == i && v[i][j].second == j - 1) {
    temp += 'R';
    s(i, j - 1, I, J, v);
  } else if (v[i][j].first == i && v[i][j].second == j + 1) {
    temp += 'L';
    s(i, j + 1, I, J, v);
  }
}
int main() {

  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  ll I, J, DI, DJ;
  vector<vector<ll>> montime(n, vector<ll>(m, -1));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        I = i;
        J = j;
      }
      if (a[i][j] == 'M') {
        bfs(i, j, a, n, m, montime);
      }
    }
  }
  vector<vector<pair<ll, ll>>> v(n, vector<pair<ll, ll>>(m, {0, 0}));
  vector<vector<ll>> vis(n, vector<ll>(m, 0));
  v[I][J] = {I, J};
  vis[I][J] = 1;
  vector<ll> destination(2);
  ll dis = bfss(I, J, montime, v, a, vis, destination);

  if (dis == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << dis << endl;

    s(destination[0], destination[1], I, J, v);
    reverse(temp.begin(), temp.end());
    cout << temp << "\n";
  }
  return 0;
}
