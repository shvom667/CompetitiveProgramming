
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
  ll n, m;
  cin >> n >> m;
  char g[n][m];
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  Vec<char> r = {'v', 'i', 'k', 'a'};
  ll ptr = 0;
  for (ll j = 0; j < m; j++) {
    for (ll i = 0; i < n; i++) {
      if (ptr < r.size() && g[i][j] == r[ptr]) {
        ptr++;
        break;
      }
    }
  }
  if (ptr == r.size()) {
    cout <<"YES\n";
  } else {
    cout << "NO\n";
  }

}
