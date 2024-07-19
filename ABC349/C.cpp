
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

void solve() {
  string t, s;
  cin >> s >> t;
  Vec<ll> ind[26];
  ll n = s.size();
  for (ll i = 0; i < (ll)s.size(); i++) {
    ind[s[i]-'a'].pb(i);
  }
  if (t.back() == 'X') 
  {
    ll itr = 0;
    for (ll i = 0; i < n; i++) {
      if (itr < 2 && s[i] - 'a' == t[itr] - 'A') {
        itr++;
      }
    }
    if (itr == 2) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  else
  {
    ll itr = 0;
    for (ll i = 0; i < n; i++)
      if (itr < 3 && s[i] - 'a' == t[itr] - 'A')
        itr++;
    if (itr == 3)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
