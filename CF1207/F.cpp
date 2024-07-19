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
  t = 1;
  while (t--) solve();
}
const int N = 5e5 + 20;
const int M = 710;
int a[N];
ll b[M][M];
void solve() {
  int q;
  cin >> q;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (ll ux = 1; ux < M; ux++) {
        b[ux][x%ux] += y;
      }
    }
    if (t == 2) {
      if (x < M) {
        cout << b[x][y] << "\n";
      } else {
        ll fans = 0;
        for (ll sp = y; sp <= N; sp+=x) {
          fans += a[sp];
        }
        cout << fans << "\n";
      }
    }
  }
}
