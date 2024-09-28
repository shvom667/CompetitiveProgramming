#include<bits/stdc++.h>
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

void solve() {
  set<pair<ll, ll>> pq;
  pq.insert({1,2});
  pq.insert({3,4});
  pq.insert({1,5});
  for (auto& [u,  v]: pq) {
    cout << u << " " << v << "\n";
  }
}