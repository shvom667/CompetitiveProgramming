
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
  ll n, m, d;
  cin >> n >> m >> d;
  ll a[n + 1];
  ll fans=0, sum=0;
  multiset<ll> ms;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      if ((ms.size()) < m) {
        ms.insert(a[i]);
        sum += a[i];
      }
      else if (ms.size() == m) {
        if (a[i] > *begin(ms)) {
          sum -= *begin(ms);
          ms.erase(ms.begin());
          ms.insert(a[i]);
          sum += a[i];
        }
      }
    }
    fans=max(fans, sum - i*d);
  }
  cout << fans << "\n";
}
