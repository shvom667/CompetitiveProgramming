
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
const ll N = 150;
ll tab[N][N];

void solve() {
  ll n, m;
  cin >> n >> m;
  Vec<ll> x, y;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++) {
      char c;
      cin >> c;
      tab[i][j] = c - '0';
    }

  for (ll i = n; i >= 3; i--)
    for (ll j = m; j >= 1; j--) {
      if (tab[i][j] == 1) {
        x.pb(i), y.pb(j);
        tab[i][j] ^= 1;
        x.pb(i-1), y.pb(j);
        tab[i-1][j] ^= 1;
        if (j - 1 >= 1) {
          x.pb(i-1), y.pb(j-1);
          tab[i-1][j-1] ^= 1;
        } else {
          x.pb(i-1), y.pb(j+1);
          tab[i-1][j+1] ^= 1;
        }
      }
    }

  for (ll j = m; j >= 3; j--) {
    if (tab[1][j] == 0 && tab[2][j] == 0) continue;
    else if (tab[1][j] == 1 && tab[2][j] == 1) {
      x.pb(1), y.pb(j);
      tab[1][j] ^= 1;
      x.pb(2), y.pb(j);
      tab[2][j] ^= 1;
      x.pb(1), y.pb(j-1);
      tab[1][j-1] ^= 1;
    }
    else if (tab[1][j] == 1 && tab[2][j] == 0) {
      x.pb(1), y.pb(j);
      tab[1][j] ^= 1;
      x.pb(1), y.pb(j-1);
      tab[1][j-1] ^= 1;
      x.pb(2), y.pb(j-1);
      tab[2][j-1] ^= 1;
    }
    else {
      x.pb(2), y.pb(j);
      tab[2][j] ^= 1;
      x.pb(1), y.pb(j-1);
      tab[1][j-1] ^= 1;
      x.pb(2), y.pb(j-1);
      tab[2][j-1] ^= 1;
    }
  }
  ll c = tab[1][1] + tab[1][2] + tab[2][1] + tab[2][2];
  //cout << c << "\n";
  if (c == 4) {
    x.pb(1), y.pb(1);
    x.pb(2), y.pb(1);
    x.pb(2), y.pb(2);


    x.pb(1), y.pb(2);
    x.pb(2), y.pb(1);
    x.pb(2), y.pb(2);


    x.pb(1), y.pb(1);
    x.pb(1), y.pb(2);
    x.pb(2), y.pb(1);

    x.pb(1), y.pb(1);
    x.pb(1), y.pb(2);
    x.pb(2), y.pb(2);
  }

  if (c == 3) {
    for(ll i = 1; i <= 2; i++)
      for(ll j = 1; j <= 2; j++)
        if (tab[i][j] == 1)
          x.pb(i), y.pb(j);
  }
  auto solve2 = [&] () {
    if (tab[1][1] && tab[1][2]) {
      x.pb(1), y.pb(2);
      x.pb(2), y.pb(1);
      x.pb(2), y.pb(2);


      x.pb(1), y.pb(1);
      x.pb(2), y.pb(1);
      x.pb(2), y.pb(2);
    }
    if (tab[1][1] && tab[2][1]) {
      x.pb(1), y.pb(1);
      x.pb(1), y.pb(2);
      x.pb(2), y.pb(2);


      x.pb(2), y.pb(1);
      x.pb(1), y.pb(2);
      x.pb(2), y.pb(2);
    }
    if (tab[2][1] && tab[2][2]) {
      x.pb(2), y.pb(2);
      x.pb(1), y.pb(1);
      x.pb(1), y.pb(2);


      x.pb(2), y.pb(1);
      x.pb(1), y.pb(1);
      x.pb(1), y.pb(2);
    }
    if (tab[1][2] && tab[2][2]) {
      x.pb(2), y.pb(2);
      x.pb(1), y.pb(1);
      x.pb(2), y.pb(1);


      x.pb(1), y.pb(2);
      x.pb(1), y.pb(1);
      x.pb(2), y.pb(1);
    }
    if (tab[1][1] && tab[2][2]) {
      x.pb(2), y.pb(2);
      x.pb(1), y.pb(2);
      x.pb(2), y.pb(1);


      x.pb(1), y.pb(1);
      x.pb(1), y.pb(2);
      x.pb(2), y.pb(1);
    }
    if (tab[2][1] && tab[1][2]) {
      x.pb(1), y.pb(1);
      x.pb(1), y.pb(2);
      x.pb(2), y.pb(2);


      x.pb(1), y.pb(1);
      x.pb(2), y.pb(1);
      x.pb(2), y.pb(2);
    }
  };
  if (c == 2) {
    solve2();
  }
  if (c == 1) {
    if(max(tab[1][1], tab[1][2]) == 1) {
      if (tab[1][1] == 1) {
        x.pb(1), y.pb(1);
        tab[1][1] ^= 1;
        x.pb(2), y.pb(1);
        tab[2][1] ^= 1;
        x.pb(2), y.pb(2);
        tab[2][2] ^= 1;
      }
      if (tab[1][2] == 1) {
        x.pb(1), y.pb(2);
        tab[1][2] ^= 1;
        x.pb(2), y.pb(1);
        tab[2][1] ^= 1;
        x.pb(2), y.pb(2);
        tab[2][2] ^= 1;
      }
    } else {
      if (tab[2][1] == 1) {
        x.pb(2), y.pb(1);
        tab[2][1] ^= 1;
        x.pb(1), y.pb(1);
        tab[1][1] ^= 1;
        x.pb(1), y.pb(2);
        tab[1][2] ^= 1;
      }
      if (tab[2][2] == 1) {
        x.pb(2), y.pb(2);
        tab[2][2] ^= 1;
        x.pb(1), y.pb(1);
        tab[1][1] ^= 1;
        x.pb(1), y.pb(2);
        tab[1][2] ^= 1;
      }
    }
    //cout << tab[1][1] << tab[1][2] << "\n" << tab[2][1] << tab[2][2] << "\n";
    solve2();
  }
  assert(((ll)x.size()) % 3 == 0);
  cout << x.size() / 3 << "\n";
  for (ll i = 0; i < (ll) x.size() ; i += 3) {
    cout << x[i] << " " << y[i] << " " << x[i + 1] << " " << y[i + 1]  << " " << x[i + 2] << " " << y[i+2] <<  "\n";
  }
}
