
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
  ll l = 1, r = 2648956422ll;

  ll n;
  cin >> n;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    bool ok = true;
    if ((m*(m-1))/2 >= n) {
      ok = true;
    } else {
      ok = false;
    }
    if (ok) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  if (((l*(l-1))/2 > n)) l--;
    cout << l + (n - (l*(l-1))/2) << "\n";
}
