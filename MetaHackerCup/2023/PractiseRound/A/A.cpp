#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

ll solve(ll s, ll d, ll k);
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  for (ll c = 1; c <= t; c++) {
    ll s, d, k;
    cin >> s >> d >> k;
    string ans = solve(s, d, k) ? "YES" : "NO";     
    cout << "Case #" << c << ": " << ans << "\n";
  }
}

ll solve(ll s, ll d, ll k) {
    // cout << s << " " << d << " " << k << "\n";
    if (k <= min(2*s+2*d-1,s+2*d)) {
        return 1;
    }    
    return 0;
}