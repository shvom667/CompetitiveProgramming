#include<bits/stdc++.h>
#include<atcoder/scc>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
const ll N = 2e5 + 20;
ll a[N];
ll r[N];
void solve() {
  ll n, k; 
  cin >> n >> k;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    r[i] = (a[i] > n ? -1 : (a[i] - i + n) % n);
  }
  Vec<ll> adj[n + 1];
  Vec<Vec<ll>> edges;
  for (ll i = 1; i <= n; i++) {
    if (r[i] != -1) {
      adj[r[i]].pb((r[i] + a[i])%n);
      edges.pb({r[i], (r[i] + a[i])%n});
    }
  }

}
