
#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
const ll N = 5e5+20;
ll p[N];
Vec<ll> tp;
void pre() {
  for (ll i = 2; i < N; i++) {
    if (p[i] != 0)
      continue;
    if (p[i] == 0)
    {
      for (ll j = 2; j * i < N; j++)
        p[i*j] = 1;
    }
  }
  for (ll i = 2; i < N; i++)
    if (p[i] == 0)
      tp.pb(i);
}
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  pre();
  ll t; 
  cin >> t; 
  while (t--) solve();
}

void solve() {
  ll n;
  cin >> n;
  cout << tp[n-1] << '\n';
}
