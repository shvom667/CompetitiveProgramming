#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
//#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

const ll INF=1e18;
using pl = pair<ll, ll>;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), d(n);

  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= k;
    d[i] = a[i];
    if (i) d[i] = a[i] - a[i - 1];
  }

  priority_queue<ll, vector<ll>, greater<ll>> Q;

  ll ans=0;
  int prev = 0;
  
  for (ll i = 0; i < n; i++) {
    if (d[i] < 0) {
      Q.push(d[i] + k);
    } else {
      Q.push(d[i]);
      ans += Q.empty() ? d[i] : min(d[i], Q.top());
      Q.pop();
    }
  }
  return ans;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}


