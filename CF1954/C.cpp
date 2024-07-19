
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
  string x, y;
  cin >> x >> y;
  ll n = x.size();
  string xx="", yy="";
  bool ok = false;
  for (ll i = 0; i < n; i++) {
    if (ok) {
      xx += min(x[i], y[i]);
      yy += max(x[i], y[i]);
    }
    if (!ok) {
      if (x[i] == y[i]) {
        xx += x[i];
        yy += y[i];
      } else {
        ok = true;
        xx += max(x[i],y[i]);
        yy += min(x[i],y[i]);
      }
    }
  }
  cout << xx << " " << yy << '\n';

}
