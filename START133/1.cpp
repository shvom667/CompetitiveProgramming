
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
using pl = pair<ll, ll>;
using ld = long double;
const ld eps = 1e-12;
void solve() {
  ll n;
  cin >> n;
  ll a[n];
  Vec<pl> p;
  ll fans=0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      fans += n-1;
    }else{
      p.pb({a[i], i});
    }
  }
  for (ll i = 0; i < (ll)p.size(); i++) {
    for (ll k = 0; k < min((ll)p.size(), 30ll); k++) {
      if (p[i].second > 30) break;
      ld aa, bb;
      aa = bb = 1;
      ll ii, jj;
      ii = p[i].second;
      jj = p[k].second;
      aa *= jj*log2(a[ii]);
      bb *= log2(a[jj]);
      if (bb - aa < eps) {
        fans++;
      } else {
      }
    }
  }
  cout << fans << '\n';
}
