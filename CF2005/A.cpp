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

void solve() {
    ll n;
    cin >> n;
    ll j = 0;
    ll i = 0;
    vector<char> v = {'a','e','i','o','u'};
    string s = "";
    for (ll k = 0; k < 5; k++) {
        // for (i = 0; i < n; i++) {
            ll cnt = n / 5 + (k < n%5);
            while(cnt--){
                s += v[k];
            }
        // }
    }
    cout << s << "\n";
}