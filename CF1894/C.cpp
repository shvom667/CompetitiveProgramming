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
const ll N = 2e5 + 20;
ll a[N];
void solve() {
  ll n, k;
  cin >> n >> k;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ci = n;
  ll itr = 0;
  while (itr <= 2*n) {
    if (a[ci] > n) {
      break;
    }
    itr++;
    ll ni;
    if (ci - a[ci] == 0) {
      ni = n;
    }
    if (ci - a[ci] < 0) {
      ni = ci - a[ci] + n;
    }
    if (ci - a[ci] > 0) {
      ni = ci - a[ci];
    }
    ci = ni;
  }
  if (itr > n) {
    cout << "Yes\n";
    return;
  }
  if (itr >= k) {
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}
