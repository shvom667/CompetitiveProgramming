#include <bits/stdc++.h>

using namespace std;

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
vector<vector<int>> adj;
vector<int> dist;
vector<bool> seen;

void dfs(int i, int p) {
  seen[i]=true;
  for (auto& ch : adj[i]){ 
    if (ch != p) {
      dist[ch] = dist[i] + 1;
      dfs(ch, i);
    }
  }
}

int secondsToDisarmNetwork(int target, int network_nodes, vector<int> network_from, vector<int> network_to) {
  int n = network_nodes;
  adj.clear();
  adj = vector<vector<int>> (n + 1);
  dist = vector<int> (n+1,0);
  seen = vector<bool> (n+1,false);
  for (int i = 0; i < (int)network_from.size(); i++) {
    adj[network_from[i]].push_back(network_to[i]);
    adj[network_to[i]].push_back(network_from[i]);
  }
  dfs(target, -1);
  int fans = 1e9;
  for (int i = 1; i <= n; i++)
    fans = min(fans, dist[i]);
  return fans;
}
int main() {
  int T, NN;
  vector<int> NF;
  vector<int> NT;
  cin >> T >> NN;
  for (int i = 0; i < NN-1; i++) {
    int x, y;
    cin >> x >> y;
    NF.push_back(x), NT.push_back(y);
  }
  cout << secondsToDisarmNetwork(T,NN,NF,NT) << "\n";
  dbg(dist);

	return 0;
}
