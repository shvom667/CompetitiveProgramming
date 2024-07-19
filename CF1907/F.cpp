
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using Vec = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}

void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n), sa, ra;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ra = sa = a;
  sort(begin(sa), end(sa));
  ra = sa;
  reverse(begin(ra), end(ra));
  ll m, M;
  m = *min_element(begin(a), end(a));
  M = *max_element(begin(a), end(a));
  if (a == sa) {
    cout << 0 << "\n";
    return;
  }
  if (a == ra) {
    cout << 1 << "\n";
    return;
  }
  bool o, t;
  o = t = false;
  Vec<ll> f1, f2;
  if (a[0] <= a[n-1]) {
    for (ll i = 0; i < n-1; i++) {
      if (a[i] <a[i+1]) {
        f1.pb(i);
      }
    }
    if (f1.size() == 1 && a[f1[0]]==m && a[f1[0]+1] == M) {
      o = true;
    }
  }
  if (a[0] >= a[n-1]) {
    for (ll i = 0; i + 1 < n; i++) {
      if (a[i] > a[i + 1]) {
        f2.pb(i);
      }
    }
    if (f2.size() == 1 && a[f2[0]] == M && a[f2[0] + 1] == m) {
      t = true;
    }
  }
  if (!o && !t) {
    cout << -1 << "\n";
    return;
  }
  ll fans=1e16;
  if (o) {
    fans = min(fans, 1+f1[0]+1);
    fans = min(fans, n - f1[0]);
  }
  if (t) {
    fans = min(fans, n-1-f2[0]);
    fans = min(fans, 3+f2[0]);
  }
  cout << fans << "\n";
}
