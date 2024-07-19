
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
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    deque<ll> d;
    for (ll i = 0; i < n; i++) {
        d.pb(a[i]);
        while (d.size() > 1) {
            if (d[(ll)d.size()-1] == d[(ll)d.size() - 2]) {
                ll b = d.back();
                d.pop_back();
                d.pop_back();
                d.pb(b+1);
            }else{
                break;
            }
        }
    }
    cout << (ll)d.size() << '\n';
}
