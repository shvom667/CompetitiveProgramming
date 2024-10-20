#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve() {
  ll n; cin >> n;
  vector<ll> H(n);

  for (ll i = 0; i < n; i++) {
    cin >> H[i];
  }
  auto ans = [&] (vector<ll> h) {
    vector<ll> ph(n);
  
    for (ll i = 0; i < n; i++) {
      ph[i] = h[i];
      if (i) ph[i] += ph[i-1];
    }
  
    vector<ll> dl(n);
  
    deque<ll> dq;
    dbg(h); 
    auto get = [&] (ll x, ll y) {
      ll sum = 0;
      sum += ph[y];
      if (x) sum -= ph[x-1];
      ll len = y - x;
      len = min(len, h[y]-1);
      sum -= h[y] * (len);
      sum += (len) * (len+1) / 2;
      return sum;
    };
  
    for (ll i = 0; i < n; i++) {
      dbg(dq);
      while (!dq.empty() && h[dq.back()]-dq.back() > h[i] - i) {
        dq.pop_back();
      }
      ll j;
      j = dq.empty() ? -1 : dq.back();
      if (j >= 0) {
        dl[i] += dl[j] - h[j];
      }
      if (i == 3) {
        dbg(j);
        dbg(i, dq);
        dbg(get(j+1,i));
      }
      dl[i] += get(j + 1, i);
  
      dq.push_back(i);
    }
    return dl;
  };
  
  vector<ll> h,hh;
  h = H, hh = H;
  reverse(begin(hh),end(hh));

  vector<ll> dl, dr;
  dl = ans(h);
  dr = ans(hh);
  reverse(begin(dr),end(dr));

  dbg(dl,dr);

  ll fans = 1e18;
  for(ll i = 0; i < n; i++) {
    ll cur = dl[i] + dr[i] - h[i];

    fans = min(fans, cur);
  }
  return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
