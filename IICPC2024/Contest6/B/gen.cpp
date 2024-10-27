#include <bits/stdc++.h>
using ll = int;
using namespace std;

int rand(int a, int b) {
  return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  


  ll n = rand(2, 6);
  ll m = rand(2, 15);
  
  set<pair<ll, ll>> edges;

  for (ll i = 1; i <= m; i++) {
    ll u, v;
    u = rand(1, n);
    v = rand(1, n);
    while (u == v) {
      u = rand(1, n);
      v = rand(1, n);
    }
    edges.insert({u, v});
  }
  m = edges.size();
  cout << n << " " << m << "\n";
  for (auto& [u, v] : edges) {
    cout << u << " " << v << "\n";
  }
}
