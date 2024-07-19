#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--)
    solve();
}

struct Foo {
  ll pair_id, u, v;
};

class Compare {
public:
  bool operator()(Foo a, Foo b) { return a.pair_id > b.pair_id; }
};

/*
 * Custom Compare For Priority Queue
 */

Foo foo;
ll id_itr;
void solve() {
  id_itr = 0;
  priority_queue<Foo, vector<Foo>, Compare> pq;
  ll n;
  cin >> n;
  Vec<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  for (ll i = 1; i < n; i++)
    if (gcd(a[i], a[i + 1]) == 1) {
      foo.pair_id = id_itr++;
      foo.u = i;
      foo.v = i + 1;
      pq.push(foo);
    }
  if (gcd(a[n], a[1]) == 1) {
    foo.pair_id = id_itr++;
    foo.u = n;
    foo.v = 1;
    pq.push(foo);
  }
  set<ll> index_set;
  for (ll i = 1; i <= n; i++)
    index_set.insert(i);
  Vec<ll> res;
  while (!pq.empty()) {
    Foo t = pq.top();
    pq.pop();
    if (index_set.count(t.u) == 0 || index_set.count(t.v) == 0) 
      continue;
    auto it = index_set.upper_bound(t.v);
    if (it == end(index_set)) {
      foo.pair_id = id_itr++;
      foo.u = t.u;
      foo.v = *begin(index_set);
      if (gcd(a[foo.u], a[foo.v]) == 1)
        pq.push(foo);
    } else {
      foo.pair_id = id_itr++;
      foo.u = t.u;
      foo.v = *it;
      if(gcd(a[foo.u], a[foo.v]) == 1)
        pq.push(foo);
    }
    res.pb(t.v);
    index_set.erase(index_set.find(t.v));
  }
  cout << res.size() << " ";
  for (auto& x : res)
    cout << x <<  " ";
  cout << "\n";
}
