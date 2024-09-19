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

ll get(vector<ll> u) {
    ll n = u.size();
    ll cnt =0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            bool ok = true;
            for (ll k = i + 1; k <= j; k++) {
                if (u[k] < u[k-1]) ok = false;
            }
            if (ok) cnt++;
        }
    }
    return cnt;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll fans = get(v); 
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            vector<ll> u = v;
            swap(u[i], u[j]);
            
            fans = max(fans, get(u));
        }
    }
    cout << fans << "\n";
}