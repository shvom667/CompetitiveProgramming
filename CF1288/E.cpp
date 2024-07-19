
/*
  And all I am is a man
  I want the world in my hands
  I hate the beach
  But I stand in California with my toes in the sand
  Use the sleeves of my sweater
  Let's have an adventure
  Head in the clouds but my gravity centered
  Touch my neck and I'll touch yours
  You in those little high waisted shorts, oh
*/

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define fbo find_by_order(x)
#define ook(x) order_of_key(x)
/*
 * find_by_order(x) : return the (x + 1) th smallest element
 * order_of_key(x)  : number of elements strictly less than x
 */

using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t = 1;
  while (t--) solve();
}

void solve() {
  ll n, m;
  cin >> n >> m;
  ll a[m];
  for (ll i = 0; i < m; i++)
    cin >> a[i];
  map<ll, ll> mp;
  Vec<ll> u(n+1, 0);
  Vec<bool> seen(n + 1, false);
  ordered_set s;
  for (ll i = 0; i < m; i++) {
    if (mp.find(a[i]) == mp.end()) {
    }else{
      ll pi = mp[a[i]];
      ll sm = s.ook(pi);
      sm++;
      u[a[i]] = max(u[a[i]], (ll)s.size()-sm);
      s.erase(s.find(pi));
    }
    mp[a[i]] = i;
    s.insert(i);
  }
  set<ll> ss;
  for (ll i = m - 1; i >= 0; i--) {
    if (seen[a[i]]==false) {
      u[a[i]] = max(u[a[i]], (ll)ss.size());
    }
    ss.insert(a[i]);
    seen[a[i]]=true;
  }
  ordered_set bg;
  Vec<ll> v(n + 1, 0);
  seen = vector<bool> (n + 1, false);
  for (ll i = 0; i < m; i++) {
    if (seen[a[i]] == false) {
      ll sm = bg.ook(a[i]);
      ll gr = bg.size() - sm;
      v[a[i]] = gr;
    }
    bg.insert(a[i]);
    seen[a[i]] = true;
  }
  for (ll i = 1; i <= n; i++) {
    if (seen[i] == false) {
      ll sm = bg.ook(i);
      ll gr = bg.size() - sm;
      v[i] = gr;
    }
  }
  Vec<ll> p(n+1), P(n + 1);
  for (ll i = 1; i <= n; i++) {
    p[i] = P[i] = i;
  }
  for (ll i = 0; i < m; i++) {
    p[a[i]] = 1;
  }
  set<ll> tot;
  for (ll i = 0; i < m; i++) {
    tot.insert(a[i]);
  }

  for (ll i = 1; i <= n; i++) {
    P[i] = max(P[i], i + v[i]);
  }
  for (ll i = 1; i <= n; i++) {
    P[i] = max(P[i], 1 + u[i]);
  }
  for (ll i = 1; i <= n; i++) {
    cout << p[i] << " " << P[i] << "\n";
  }
}
