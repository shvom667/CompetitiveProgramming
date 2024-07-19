#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define mk(a, b) make_pair(a, b)
#define pr(n) printf("%d\n", n)
#define sc(n) scanf("%d", &n)
#define scll(n) scanf("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll

int n, q;
const ll N = 2e5 + 20;
const ll M = 20;
int a[N];
int arr[N];
int table[N][M + 1]; // 2^16 > 10e5
int k = M;

void buildTable() {
  int i;
  for (i = 0; i < n; i++) {
    table[i][0] = arr[i];
  }
  int j;
  for (j = 1; j <= k; j++) {
    for (i = 0; i <= n - (1 << j); i++) {
      table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
  }
  return;
}

int query(int l, int r) {
  int i, gc = 0;
  for (i = k; i >= 0; i--) {
    if (l + (1 << i) - 1 <= r) {
      gc = __gcd(gc, table[l][i]);
      l = l + (1 << i);
    }
  }
  return gc;
}

signed main(void) {
  ll T;
  cin >> T;
  while (T--) {
    cin >> n;
    ll a[n + 1];
    int i;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (i) {
        arr[i] = abs(a[i] - a[i-1]);
      }
    }
    //for (ll i = 0; i < n; i++)
    //  cout << arr[i] << ' ';
    //cout << '\n';
    buildTable();
    ll f = 0;
    for (ll i = 1; i < n; i++) {
      ll l = i, r = n-1;
      while (l <= r) {
        ll mid = l + (r - l) / 2;
        bool ok = false;
        ok=query(i, mid)>1;
        if (ok) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      f = max(f, r-i+1);
    }
    cout << f + 1 << '\n';
  }
}
