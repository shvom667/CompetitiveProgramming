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

bool ask(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    ll r;
    cin >> r;
    if (r == -1) {
        assert(false);
    }
    return (r == 1 ? false : true);
}
 
auto solve() {
  ll n;
  cin >> n;
  ll x = -1;
  vector<ll> par(n, -1);
  par[1] = 0;
  for (ll i = 2; i < n; i++)
  {
    if (ask(i, 1)) {
      x = i;
      par[x] = 1;
      break;
    }
    par[i] = 0;
  }
  if (x == n - 1) {
    return par;
  }
  set<ll> s;
  for (ll i = 2; i < x; i++)
    s.insert(i);
  set<ll> ns;
  ns.insert(x);

  ll nv = x + 1;
  while (true)
  {
    for (auto&it : s)
    {
      if (it == n - 1)
      {
        return par;
      }
      if (ask(it, nv))
      {
        par[nv] = it;
        ns.insert(nv);
        nv++;
        if (nv == n)
        {
          return par;
        }

      }
          
    }
    s = ns;
    ns.clear();
  }

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        
        cout << "! ";
        for (ll i = 1; i < res.size(); i++) {
            cout << res[i] << " ";
        }   cout << endl;
    }
    return 0;
}
