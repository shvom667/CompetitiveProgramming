#include <bits/stdc++.h>
#include <unistd.h> // for sleep

using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif


#define LOCAL

#ifdef LOCAL
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
  
#else
    #define rnd(...) 42
    // do other stuff
#endif



auto solve()
{
  
  return 0;
}

auto bf(ll n, vector<ll> a)
{
  ll fans = 0;
  vector<ll> best;
  for (ll i = 0; i < (1ll<<n); i++) {
    vector<ll> s(n, 0);
    for (ll b = 0; b < n; b++) {
      s[b] = ((i & (1ll<<b)) > 0);
    }
    bool ok = true;
    for (ll b = 0; b < n; b++) {
      if (b > 0) {
        if (s[b] == 1 && s[b-1] == 1) {
          ok = false;
        }
      }
    }
    if (ok) {
      vector<ll> c;
      for (ll b = 0; b < n; b++) {
        if (s[b] == 1) c.pb(a[b]);
      }
      sort(begin(c), end(c));
      if ((ll)c.size() > 0) {
        ll cur = (ll)c.size() + c[0] + c[(ll)c.size()-1];
        fans = max(fans, 
          cur
        );
        if (fans == cur) {
          best = s;
        }
      }
    }
  }
  if (true) {
    for (ll i = 0; i < n; i++) {
      if (best[i] == 0) {
        cout << a[i] << " ";
      } else {
        cout << "\e[31m" << a[i] << "\e[0m" << " ";
      }
    }
    // sleep(1);
    cout << "\n";
  }
  return fans;
}

auto stress() {
  while (true) {
    ll n = rnd(2, 10);
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
      a[i] = rnd(1, 5);
    }
    // cout << n << "\n";
    // for (auto& x : a) {
    //   cout << x << " ";
    // } cout << "\n";
    // dbg(n);
    // dbg(a);
    auto res = bf(n, a);
    // dbg(res);
  }
}



int main()
{

  #ifdef LOCAL
    stress();
    return 0;
  #endif

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++)
  {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto res = bf(n, a);
    cout << res << "\n";
  }
  return 0;
}
